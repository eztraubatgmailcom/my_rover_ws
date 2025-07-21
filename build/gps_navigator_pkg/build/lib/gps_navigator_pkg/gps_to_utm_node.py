import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from nav_msgs.msg import Odometry
import utm
from geometry_msgs.msg import Quaternion
from tf_transformations import quaternion_from_euler

class GPSToUTMNode(Node):
    def __init__(self):
        super().__init__('gps_to_utm_node')
        self.subscription = self.create_subscription(
            NavSatFix,
            '/gps/fix',
            self.gps_callback,
            10
        )
        self.publisher = self.create_publisher(Odometry, '/odometry/gps', 10)
        self.frame_id = 'odom'
        self.child_frame_id = 'base_link'

    def gps_callback(self, msg: NavSatFix):
        if msg.status.status < 0:
            self.get_logger().warn('GPS fix not available')
            return

        utm_coords = utm.from_latlon(msg.latitude, msg.longitude)

        odom = Odometry()
        odom.header.stamp = self.get_clock().now().to_msg()
        odom.header.frame_id = self.frame_id
        odom.child_frame_id = self.child_frame_id

        odom.pose.pose.position.x = utm_coords[0]
        odom.pose.pose.position.y = utm_coords[1]
        odom.pose.pose.position.z = msg.altitude

        # No orientation from GPS, set neutral quaternion
        quat = quaternion_from_euler(0, 0, 0)
        odom.pose.pose.orientation = Quaternion(x=quat[0], y=quat[1], z=quat[2], w=quat[3])

        # Inject a meaningful covariance (required by EKF)
        
        
        
        odom.pose.covariance = [
            2.0, 0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 2.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 9999.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 9999.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 9999.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0, 5.0
        ] 
        
        odom.twist.covariance = [0.0] * 36  # Twist unknown for GPS-only

        self.publisher.publish(odom)

def main(args=None):
    rclpy.init(args=args)
    node = GPSToUTMNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
