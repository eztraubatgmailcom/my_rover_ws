import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist
from safety_interfaces.msg import SafetyStatus

class JoyToTwistNode(Node):
    def __init__(self):
        super().__init__('joy_to_twist')
        self.joy_sub = self.create_subscription(Joy, '/joy', self.joy_callback, 10)
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.safety_sub = self.create_subscription(SafetyStatus, '/safety_status', self.safety_callback, 10)

        self.safety = SafetyStatus()
        self.safety.front_clear = True
        self.safety.back_clear = True
        self.safety.left_clear = True
        self.safety.right_clear = True

        self.get_logger().info("🎮 joy_to_twist node started with safety awareness")

    def safety_callback(self, msg: SafetyStatus):
        self.safety = msg

    def joy_callback(self, msg: Joy):
        twist = Twist()

        forward = msg.axes[1]  # Up/Down
        turn = msg.axes[0]     # Left/Right

        # Blocking forward/backward if obstacle exists
        if forward > 0 and not self.safety.front_clear:
            self.get_logger().warn("⛔ Forward motion blocked by obstacle!")
            forward = 0.0
        elif forward < 0 and not self.safety.back_clear:
            self.get_logger().warn("⛔ Backward motion blocked by obstacle!")
            forward = 0.0

        # Warn on sharp turns with nearby obstacles
        if turn > 0.3 and not self.safety.left_clear:
            self.get_logger().warn("⚠️ Turning left — obstacle detected on the left!")
        if turn < -0.3 and not self.safety.right_clear:
            self.get_logger().warn("⚠️ Turning right — obstacle detected on the right!")

        twist.linear.x = forward * 0.5
        twist.angular.z = turn * 1.5
        self.cmd_pub.publish(twist)

def main(args=None):
    rclpy.init(args=args)
    node = JoyToTwistNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('👋 Shutting down...')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
