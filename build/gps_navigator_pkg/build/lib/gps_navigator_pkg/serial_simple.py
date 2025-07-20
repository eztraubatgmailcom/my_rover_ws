import rclpy
from rclpy.node import Node
import serial
import struct
from std_msgs.msg import UInt16

class SerialSimpleNode(Node):
    def __init__(self):
        super().__init__('serial_simple_node')
        self.ser = serial.Serial('/dev/ttyACM0', 115200, timeout=0.1)
        self.pub = self.create_publisher(UInt16, 'simple_value', 10)
        self.create_timer(0.1, self.read_serial)

    def read_serial(self):
        data = self.ser.read(2)
        if len(data) == 2:
            value = struct.unpack('<H', data)[0]
            self.get_logger().info(f"Got value: {value}")
            msg = UInt16()
            msg.data = value
            self.pub.publish(msg)

def main():
    rclpy.init()
    node = SerialSimpleNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
