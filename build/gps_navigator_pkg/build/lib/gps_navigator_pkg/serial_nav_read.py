#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import serial, struct, crcmod
from sensor_msgs.msg import Imu, MagneticField, NavSatFix
from std_msgs.msg import Header
import serial, struct, crcmod

PACKET_IMU = 0x01
PACKET_RTK = 0x02

class SerialNavNode(Node):
    def __init__(self):
        super().__init__('serial_nav_node')
        self.ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=0.1)
        self.crc16 = crcmod.mkCrcFun(0xA001, initCrc=0xFFFF, rev=True)
        self.imu_pub = self.create_publisher(Imu, 'imu/data_raw', 10)
        self.mag_pub = self.create_publisher(MagneticField, 'imu/mag', 10)
        self.gps_pub = self.create_publisher(NavSatFix, 'gps/fix', 10)
        self.create_timer(0.01, self.read_serial)

    def read_serial(self):
        if self.ser.in_waiting:
            b = self.ser.read(1)
            if not b: return
            t = b[0]
            if t == PACKET_IMU:
                pkt = self.ser.read(36 + 2)
                if len(pkt)==38 and self.check_crc(t, pkt):
                    self.publish_imu(pkt[:-2])
            elif t == PACKET_RTK:
                pkt = self.ser.read(25 + 2)
                if len(pkt)==27 and self.check_crc(t, pkt):
                    self.publish_gps(pkt[:-2])

    def check_crc(self, t, pkt):
        data, crc_bytes = pkt[:-2], pkt[-2:]
        return self.crc16(bytes([t])+data) == struct.unpack('<H', crc_bytes)[0]

    def publish_imu(self, data):
        yaw,pitch,roll,ax,ay,az,mx,my,mz = struct.unpack('<9f', data)
        now = self.get_clock().now().to_msg()
        imu = Imu(header=rclpy.msg.Header(stamp=now))
        imu.orientation.x, imu.orientation.y, imu.orientation.z = roll,pitch,yaw
        imu.linear_acceleration.x, imu.linear_acceleration.y, imu.linear_acceleration.z = ax,ay,az
        self.imu_pub.publish(imu)
        mag = MagneticField(header=imu.header)
        mag.magnetic_field.x, mag.magnetic_field.y, mag.magnetic_field.z = mx,my,mz
        self.mag_pub.publish(mag)

    def publish_gps(self, data):
        fq, lat, lon, spd, crs = struct.unpack('<Bddff', data)
        if fq != 4:
            self.get_logger().warning(f"Ignoring GPS fix_quality={fq}")
            return
        now = self.get_clock().now().to_msg()
        fix = NavSatFix(header=rclpy.msg.Header(stamp=now))
        fix.latitude, fix.longitude = lat, lon
        fix.status.status = NavSatFix.STATUS_FIX
        self.gps_pub.publish(fix)

def main():
    rclpy.init()
    node = SerialNavNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()