from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        
         # 0. Rover Robotics Driver (CAN + motion control)
        Node(
            package='roverrobotics_driver',
            executable='roverrobotics_driver',
            name='roverrobotics_driver',
            output='screen',
        ),
        
        # 1. Serial bridge for IMU & GPS
        Node(
            package='gps_navigator_pkg',
            executable='read_nav_external',
            name='serial_bridge',
            output='screen',
        ),

        # 2. EKF node (fuses IMU, wheel odom, and GPS odom)
        Node(
            package='robot_localization', executable='ekf_node',
            name='ekf_filter_node', output='screen',
            parameters=['./config/ekf.yaml']
        ),
        
        
        Node(
            package='robot_localization', executable='navsat_transform_node',
            name='navsat_transform_node', output='screen',
            parameters=['./config/navsat_transform.yaml'],
            remappings=[('imu/data', '/imu/data_raw'),
                        ('gps/fix', '/gps/fix'),
                        ('odometry/filtered', '/odometry/filtered')]
        ),
        
        # 4. Joystick-to-Twist control
        Node(
            package='joy_twist_bridge_pkg',
            executable='joy_to_twist',
            name='joy_to_twist',
            output='screen',
        ),

        # 5. Obstacle detector (publishes safety_status)
        Node(
            package='lidar_safety_pkg',
            executable='obstacle_detector_node',
            name='obstacle_detector',
            output='screen',
            parameters=[{'stop_distance': 0.5}],
        ),
    ])
