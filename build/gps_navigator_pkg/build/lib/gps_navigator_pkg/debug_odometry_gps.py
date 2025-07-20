# file: debug_odometry_gps.py
# file: debug_odometry_gps.py
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSDurabilityPolicy, QoSHistoryPolicy




class GpsOdomDebug(Node):
    def __init__(self):
        super().__init__('gps_odom_debug')
        
        qos = QoSProfile(
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=QoSReliabilityPolicy.RELIABLE,
            durability=QoSDurabilityPolicy.VOLATILE
        )
        
        self.subscription = self.create_subscription(
            Odometry,
            '/odometry/gps',
            self.listener_callback,
            qos
        )

    def listener_callback(self, msg):
        self.get_logger().info(f"\nReceived /odometry/gps message:\n{msg}")

def main(args=None):
    rclpy.init(args=args)
    node = GpsOdomDebug()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
