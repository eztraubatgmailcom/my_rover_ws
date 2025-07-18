import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry

class OdomEcho(Node):
    def __init__(self):
        super().__init__('odom_echo')
        self.sub = self.create_subscription(Odometry, '/odometry/wheels',
                                            self.cb, 10)
    def cb(self, msg):
        self.get_logger().info(f"Wheel odom → x: {msg.pose.pose.position.x:.3f}, "
                               f"vx: {msg.twist.twist.linear.x:.3f}")

def main():
    rclpy.init()
    n = OdomEcho()
    rclpy.spin(n)
    rclpy.shutdown()

if __name__=='__main__':
    main()
