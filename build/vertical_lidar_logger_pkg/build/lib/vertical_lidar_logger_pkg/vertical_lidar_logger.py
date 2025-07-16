import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
import csv
import math
import os
from datetime import datetime
import numpy as np


class VerticalLidarLogger(Node):

    def __init__(self):
        super().__init__('vertical_lidar_logger')

        # Parameters
        scan_topic = self.declare_parameter('scan_topic', '/scan').get_parameter_value().string_value
        self.get_logger().info(f"Subscribing to LIDAR topic: {scan_topic}")

        self.scan_rate_hz = 10.0  # Assuming RPLIDAR runs at 10 Hz
        self.forward_velocity_mps = 0.1  # Simulated forward speed
        self.forward_distance = 0.0
        self.last_time = self.get_clock().now()

        # Always overwrite the same CSV log file
        self.log_filename = os.path.expanduser("~/vertical_lidar_log.csv")

        with open(self.log_filename, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(['x', 'y', 'z', 'timestamp'])  # CSV header

        self.get_logger().info(f"Logging to {self.log_filename}")

        # LIDAR subscriber
        self.subscription = self.create_subscription(
            LaserScan,
            scan_topic,
            self.scan_callback,
            10
        )

    def scan_callback(self, msg):
        current_time = self.get_clock().now()
        time_diff = (current_time - self.last_time).nanoseconds / 1e9
        self.last_time = current_time

        self.forward_distance += self.forward_velocity_mps * time_diff
        angle = msg.angle_min
        timestamp = current_time.to_msg().sec + current_time.to_msg().nanosec * 1e-9

        valid_points = 0

        with open(self.log_filename, 'a', newline='') as f:
            writer = csv.writer(f)
            for r in msg.ranges:
                if math.isfinite(r) and r > 0.05:
                    x = r * math.cos(angle)
                    y = r * math.sin(angle)
                    z = self.forward_distance
                    writer.writerow([x, y, z, timestamp])
                    valid_points += 1
                angle += msg.angle_increment

        self.get_logger().info(f"Wrote {valid_points} points at Z={self.forward_distance:.2f}m")


def main(args=None):
    rclpy.init(args=args)
    node = VerticalLidarLogger()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
