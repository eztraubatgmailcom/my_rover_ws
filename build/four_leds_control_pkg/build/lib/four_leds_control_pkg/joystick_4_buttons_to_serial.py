import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import serial
from ps_serial_utils_pkg.esp32_mac_mapper import find_esp32_ports

class Joystick4ButtonsToSerial(Node):
    def __init__(self):
    #*************************
        super().__init__('joystick_4_buttons_to_serial')

        LED_MAC = '00:00:00:00:00:09'  # MAC address of the LED ESP32
        esp32_ports = find_esp32_ports()
        self.get_logger().info(f"Found ESP32s: {esp32_ports}")

        if LED_MAC in esp32_ports:
            port = esp32_ports[LED_MAC]
        else:
            self.get_logger().error("LED ESP32 not found!")
            raise RuntimeError("LED ESP32 not found!")

        try:
            self.serial_port = serial.Serial(port, 115200, timeout=1)
            self.get_logger().info(f"Opened serial port: {port}")
        except serial.SerialException as e:
            self.get_logger().error(f"Failed to open port {port}: {e}")
            raise e

        self.subscription = self.create_subscription(Joy, 'joy', self.joy_callback, 10)
        self.prev_buttons = [0, 0, 0, 0]

    def send_command(self, cmd):
    #*********************************
        try:
            self.serial_port.write(cmd.encode('utf-8'))
            self.get_logger().info(f"Sent: {cmd}")
        except serial.SerialException as e:
            self.get_logger().error(f"Failed to send: {cmd} - {e}")

    def joy_callback(self, msg):
    #*******************************
        buttons = msg.buttons
        mapping = ['s', 'x', 'c', 't']

        for i in range(4):
            if buttons[i] and not self.prev_buttons[i]:
                self.send_command(mapping[i])

        self.prev_buttons = buttons[:4]

def main(args=None):
#**************************
    rclpy.init(args=args)
    node = Joystick4ButtonsToSerial()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()