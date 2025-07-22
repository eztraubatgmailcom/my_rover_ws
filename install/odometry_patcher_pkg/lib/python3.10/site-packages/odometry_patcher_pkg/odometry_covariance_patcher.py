#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry

class OdometryCovariancePatcher(Node):
    def __init__(self):
        super().__init__('odometry_covariance_patcher')
        self.sub = self.create_subscription(
            Odometry,
            '/odometry/wheels',
            self.callback,
            10)
        self.pub = self.create_publisher(
            Odometry,
            '/odometry/wheels_cov',
            10)

        self.pose_covariance = [
            0.05, 0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.05, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.01, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.01, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.01, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0, 0.02]

    def callback(self, msg):
        try:
            msg.pose.covariance = list(self.pose_covariance)  # force type to list[float]
            self.pub.publish(msg)
            self.get_logger().info('Published patched message')
        except Exception as e:
            self.get_logger().error(f'Failed to patch: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = OdometryCovariancePatcher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
