import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu, MagneticField
from sensor_msgs.msg import NavSatFix, NavSatStatus
import serial, struct, time

class SerialBridge(Node):
    def __init__(self):
        super().__init__('serial_bridge')
        self.connect_serial()
        self.pub_imu = self.create_publisher(Imu, 'imu/data_raw', 10)
        self.pub_mag = self.create_publisher(MagneticField, 'imu/mag', 10)
        self.pub_gps_fix = self.create_publisher(NavSatFix, 'gps/fix', 10)
        self.timer = self.create_timer(0.005, self.read_serial)

    def connect_serial(self):
        try:
            self.ser = serial.Serial('/dev/ttyACM0', 921600, timeout=0.1)
            self.get_logger().info("Serial port opened at 921600 baud.")
        except Exception as e:
            self.get_logger().error(f"Failed to open serial port: {e}")
            self.ser = None

    def read_serial(self):
        if self.ser is None:
            self.connect_serial()
            return

        try:
            while self.ser.in_waiting > 0:
                hdr = self.ser.read(1)
                if not hdr:
                    return

                if hdr == b'\x01':  # IMU
                    expected = 40 + 2  # 10 floats * 4 bytes + CRC
                    data = self.ser.read(expected)
                    if len(data) != expected:
                        self.get_logger().warn(f"IMU: expected {expected}B, got {len(data)}B. Skipping.")
                        continue

                    payload, crc_bytes = data[:-2], data[-2:]
                    crc_recv = struct.unpack('<H', crc_bytes)[0]
                    if crc_recv != calc_crc(payload, prepend=hdr):
                        self.get_logger().warn("IMU CRC failed.")
                        continue

                    qr, qi, qj, qk, ax, ay, az, mx, my, mz = struct.unpack('<10f', payload)
                    now = self.get_clock().now().to_msg()

                    imu = Imu()
                    imu.header.frame_id = 'imu_link'
                    imu.header.stamp = now
                    imu.orientation.w = qr
                    imu.orientation.x = qi
                    imu.orientation.y = qj
                    imu.orientation.z = qk
                    imu.orientation_covariance = [0.001]*9
                    imu.angular_velocity_covariance = [0.001]*9
                    
                    imu.linear_acceleration.x = ax
                    imu.linear_acceleration.y = ay
                    imu.linear_acceleration.z = az
                    imu.linear_acceleration_covariance = [0.01]*9
                    
                    self.pub_imu.publish(imu)

                    mag = MagneticField()
                    mag.header.frame_id = 'imu_link'
                    mag.header.stamp = now
                    mag.magnetic_field.x = mx
                    mag.magnetic_field.y = my
                    mag.magnetic_field.z = mz
                    mag.magnetic_field_covariance = [0.1] * 9
                    self.pub_mag.publish(mag)

                elif hdr == b'\x02':  # GPS
                    expected = 1 + 8 + 8 + 4 + 4 + 2
                    data = self.ser.read(expected)
                    if len(data) != expected:
                        self.get_logger().warn(f"GPS: expected {expected}B, got {len(data)}B.")
                        continue

                    payload, crc_bytes = data[:-2], data[-2:]
                    crc_recv = struct.unpack('<H', crc_bytes)[0]
                    if crc_recv != calc_crc(payload, prepend=hdr):
                        self.get_logger().warn("GPS CRC failed.")
                        continue

                    fq, lat, lon, sp, alt = struct.unpack('<Bddff', payload)
                    now = self.get_clock().now().to_msg()
                    fix = NavSatFix()
                    fix.header.frame_id = 'gps_link'
                    fix.header.stamp = now
                    fix.status.status = fq     
                    fix.status.service = NavSatStatus.SERVICE_GPS
                    fix.latitude = lat
                    fix.longitude = lon
                    fix.altitude = alt  
                    
                    cov = [
                        0.0001, 0.0,    0.0,
                        0.0,    0.0001, 0.0,
                        0.0,    0.0,    0.01
                    ]
                    fix.position_covariance = cov
                    fix.position_covariance_type = NavSatFix.COVARIANCE_TYPE_APPROXIMATED
                    self.pub_gps_fix.publish(fix)

                else:
                    self.get_logger().warn(f"Unknown packet header: {hdr.hex()}")
                    # optional: consume one byte or flush until next valid header
        except (serial.SerialException, OSError) as e:
            self.get_logger().error(f"Serial port error: {e}")
            self.ser.close()
            self.ser = None

def calc_crc(data: bytes, prepend=b'') -> int:
    crc = 0xFFFF
    for b in prepend + data:
        crc ^= b
        for _ in range(8):
            crc = (crc >> 1) ^ 0xA001 if (crc & 1) else crc >> 1
    return crc

def main(args=None):
    rclpy.init(args=args)
    node = SerialBridge()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
