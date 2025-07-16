import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys
import termios
import tty

class KeyboardControllerNode(Node):
    def __init__(self):
        super().__init__('keyboard_controller_node')
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.get_logger().info('Keyboard Controller Node has started. Use arrow keys to move the rover. CTRL+C to stop.')
        self.settings = termios.tcgetattr(sys.stdin)
        self.run()

    def get_key(self):
        tty.setraw(sys.stdin.fileno())
        key = sys.stdin.read(3)
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)
        return key

    def run(self):
        move_cmd = Twist()
        while rclpy.ok():
            key = self.get_key()
            if key == '\x1b[A':   # UP
                move_cmd.linear.x = 0.5
                move_cmd.angular.z = 0.0
            elif key == '\x1b[B': # DOWN
                move_cmd.linear.x = -0.5
                move_cmd.angular.z = 0.0
            elif key == '\x1b[C': # RIGHT
                move_cmd.linear.x = 0.0
                move_cmd.angular.z = -0.5
            elif key == '\x1b[D': # LEFT
                move_cmd.linear.x = 0.0
                move_cmd.angular.z = 0.5
            else:
                move_cmd.linear.x = 0.0
                move_cmd.angular.z = 0.0

            self.publisher_.publish(move_cmd)

def main(args=None):
    rclpy.init(args=args)
    node = KeyboardControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()