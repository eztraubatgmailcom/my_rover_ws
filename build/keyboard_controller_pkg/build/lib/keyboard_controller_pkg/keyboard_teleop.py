import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys
import termios
import tty

class KeyboardControllerNode(Node):
    def __init__(self):
        super().__init__('keyboard_controller_node')

        # Parameters
        self.declare_parameter('linear_speed', 0.5)
        self.declare_parameter('angular_speed', 0.5)
        self.linear_speed = self.get_parameter('linear_speed').value
        self.angular_speed = self.get_parameter('angular_speed').value

        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.get_logger().info('Keyboard Controller Node started. Use arrow keys to move. CTRL+C to stop.')

        self.settings = termios.tcgetattr(sys.stdin)
        self.move_cmd = Twist()

        # Create a timer to check keypress every 0.1 sec
        self.timer = self.create_timer(0.1, self.timer_callback)

    def get_key(self):
        import sys, termios, tty, os
        tty.setraw(sys.stdin.fileno())
        sys.stdin.flush()  # flush any buffered input!
        key = sys.stdin.read(3)
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)
        return key

    def timer_callback(self):
        key = self.get_key()

        if key == '\x1b[A':  # UP
            self.move_cmd.linear.x = self.linear_speed
            self.move_cmd.angular.z = 0.0
            self.get_logger().info('Moving Forward')
        elif key == '\x1b[B': # DOWN
            self.move_cmd.linear.x = -self.linear_speed
            self.move_cmd.angular.z = 0.0
            self.get_logger().info('Moving Backward')
        elif key == '\x1b[C': # RIGHT
            self.move_cmd.linear.x = 0.0
            self.move_cmd.angular.z = -self.angular_speed
            self.get_logger().info('Turning Right')
        elif key == '\x1b[D': # LEFT
            self.move_cmd.linear.x = 0.0
            self.move_cmd.angular.z = self.angular_speed
            self.get_logger().info('Turning Left')
        else:
            # If unrecognized key, stop
            self.move_cmd.linear.x = 0.0
            self.move_cmd.angular.z = 0.0

        self.publisher_.publish(self.move_cmd)

def main(args=None):
    rclpy.init(args=args)
    try:
        node = KeyboardControllerNode()
        rclpy.spin(node)
    except KeyboardInterrupt:
        print("\nKeyboard Interrupt — shutting down.")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
