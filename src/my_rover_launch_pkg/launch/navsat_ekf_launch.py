# navsat_ekf_launch.py
import os

from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_share = get_package_share_directory('my_rover_launch_pkg')
    return LaunchDescription([
        # Convert GPS -> UTM odometry
        Node(
            package='robot_localization',
            executable='navsat_transform_node',
            name='navsat_transform',
            output='screen',
            parameters=[os.path.join(pkg_share, 'config', 'navsat_transform.yaml')],
            remappings=[
                ('gps/fix', '/gps/fix'),
                ('imu/data', '/imu/data_raw'),
            ],
        ),

        # Run EKF to fuse wheels, IMU, GPS
        Node(
            package='robot_localization',
            executable='ekf_localization_node',
            name='ekf_filter_node',
            output='screen',
            parameters=[os.path.join(pkg_share, 'config', 'ekf.yaml')],
        ),

        # Joystick to velocity bridge (with safety)
        Node(
            package='joy_twist_bridge_pkg',
            executable='joy_to_twist',
            name='joy_to_twist',
            output='screen',
        ),

        # Obstacle detector from LiDAR
        Node(
            package='lidar_safety_pkg',
            executable='obstacle_detector_node',
            name='obstacle_detector',
            output='screen',
        ),
    ])
