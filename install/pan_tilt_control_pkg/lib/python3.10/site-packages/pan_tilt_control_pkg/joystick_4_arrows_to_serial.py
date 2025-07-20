import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import serial
from ps_serial_utils_pkg.esp32_mac_mapper import find_esp32_ports

class JoystickToSerial(Node):
    def __init__(self):
        super().__init__('joystick_to_serial')

        TILT_PAN_MAC = '00:00:00:00:00:01'  # EZ - Always use this MAC in "Tilt/Pan ESP32 card.
        esp32_ports = find_esp32_ports()

        if TILT_PAN_MAC in esp32_ports:
            serial_port_name = esp32_ports[TILT_PAN_MAC]
            self.get_logger().info(f"Tilt/Pan ESP32 found on {serial_port_name}")
        else:
            self.get_logger().error("Tilt/Pan ESP32 not found!")
            raise RuntimeError("Tilt/Pan ESP32 not found!")

        try:
            self.serial_port = serial.Serial(serial_port_name, 115200, timeout=1)
            self.get_logger().info(f"Opened serial port: {serial_port_name}")
        except serial.SerialException as e:
            self.get_logger().error(f"Failed to open serial port {serial_port_name}: {e}")
            raise e

        self.subscription = self.create_subscription(Joy, 'joy', self.joy_callback, 10)
        self.prev_up = 0
        self.prev_down = 0
        self.prev_left = 0
        self.prev_right = 0

    def send_command(self, command):
        try:
            self.serial_port.write(command.encode('utf-8'))
            self.get_logger().info(f"Sent: {command}")
        except serial.SerialException as e:
            self.get_logger().error(f"Failed to send command '{command}': {e}")

    def joy_callback(self, msg):
        axes = msg.axes

        up = int(axes[7] == 1.0)
        down = int(axes[7] == -1.0)
        left = int(axes[6] == -1.0)
        right = int(axes[6] == 1.0)

        # UP
        if up and not self.prev_up:
            self.send_command('U')
        elif not up and self.prev_up:
            self.send_command('x_u')

        # DOWN
        if down and not self.prev_down:
            self.send_command('D')
        elif not down and self.prev_down:
            self.send_command('x_d')

        # LEFT
        if left and not self.prev_left:
            self.send_command('L')
        elif not left and self.prev_left:
            self.send_command('x_l')

        # RIGHT
        if right and not self.prev_right:
            self.send_command('R')
        elif not right and self.prev_right:
            self.send_command('x_r')

        self.prev_up = up
        self.prev_down = down
        self.prev_left = left
        self.prev_right = right

def main(args=None):
    rclpy.init(args=args)
    node = JoystickToSerial()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
