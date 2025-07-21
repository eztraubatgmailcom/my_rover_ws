import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster

class GpsStaticTFPublisher(Node):
    def __init__(self):
        super().__init__('gps_static_tf_publisher')
        self.broadcaster = StaticTransformBroadcaster(self)
        static_transform = TransformStamped()

        static_transform.header.stamp = self.get_clock().now().to_msg()
        static_transform.header.frame_id = 'base_link'
        static_transform.child_frame_id = 'gps_link'

        static_transform.transform.translation.x = 0.0
        static_transform.transform.translation.y = 0.0
        static_transform.transform.translation.z = 0.0

        static_transform.transform.rotation.x = 0.0
        static_transform.transform.rotation.y = 0.0
        static_transform.transform.rotation.z = 0.0
        static_transform.transform.rotation.w = 1.0

        self.broadcaster.sendTransform(static_transform)
        self.get_logger().info('Static transform [base_link → gps_link] published')

def main():
    rclpy.init()
    node = GpsStaticTFPublisher()
    rclpy.spin_once(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
