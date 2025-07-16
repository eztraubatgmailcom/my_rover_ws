import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from safety_interfaces.msg import SafetyStatus

#==========================================
class ObstacleDetectorNode(Node):
#==========================================
    def __init__(self):
        super().__init__('obstacle_detector_node')
        
        self.declare_parameter('stop_distance', 0.5)
        
        self.stop_distance = self.get_parameter('stop_distance').value
        
        self.scan_sub = self.create_subscription(LaserScan, '/scan', self.scan_callback, 10)
        
        self.status_pub = self.create_publisher(SafetyStatus, '/safety_status', 10)
        
        self.get_logger().info(f"ObstacleDetectorNode started with stop_distance = {self.stop_distance} m")

    def scan_callback(self, msg: LaserScan):
    #*********************************************
        sectors = {
            'back': (-20, 20),
            'left': (70, 110),
            'front': (160, 200),
            'right': (250, 290)
        }

        angle_min_deg = msg.angle_min * 180.0 / 3.14159
        angle_increment_deg = msg.angle_increment * 180.0 / 3.14159
        status = SafetyStatus()

        for name, (deg_start, deg_end) in sectors.items():
            index_start = int((deg_start - angle_min_deg) / angle_increment_deg)
            index_end = int((deg_end - angle_min_deg) / angle_increment_deg)
            ranges = msg.ranges[max(index_start, 0):min(index_end, len(msg.ranges))]
            valid = [r for r in ranges if 0.05 < r < 10.0]
            min_distance = min(valid) if valid else float('inf')
            is_clear = min_distance >= self.stop_distance
            setattr(status, f"{name}_clear", is_clear)

        self.status_pub.publish(status)

def main(args=None):
#************************
    rclpy.init(args=args)
    node = ObstacleDetectorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
