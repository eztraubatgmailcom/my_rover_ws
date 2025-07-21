from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        
        # base_link → gps_link
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='static_tf_gps',
            arguments=[
                '0', '0', '0',   # x y z
                '0', '0', '0',   # roll pitch yaw (in radians)
                'base_link', 'gps_link'
            ],
            output='screen'
        ),
        
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='static_tf_imu',
            arguments=[
                '0', '0', '0.26',
                '0', '0', '0',
                'base_link', 'imu_link'
            ],
            output='screen'
        ),
        
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='fake_odom_tf',
            arguments=[
                '0', '0', '0', '0', '0', '0', 'odom', 'base_link'
            ],
            output='screen'
        ),
        
        # EKF Filter
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_filter_node',
            parameters=['/home/rover/my_rover_ws/src/my_rover_launch_pkg/config/ekf.yaml'],
            output='screen'
        ),

        # NavSat Transform Node (with full path!)
        Node(
            package='robot_localization',
            executable='navsat_transform_node',
            name='navsat_transform_node',
            parameters=['/home/rover/my_rover_ws/src/my_rover_launch_pkg/config/navsat_transform.yaml'],
            remappings=[
                ('/imu/data', '/imu/data_raw'),
            ],
            output='screen'
        ),

        # GPS/IMU Serial Reader
        Node(
            package='gps_navigator_pkg',
            executable='read_nav_external',
            name='serial_bridge',
            output='screen'
        ),

        # Rover CAN Driver
        Node(
            package='roverrobotics_driver',
            executable='roverrobotics_driver',
            name='roverrobotics_driver',
            output='screen'
        ),

        # Obstacle Detector
        Node(
            package='lidar_safety_pkg',
            executable='obstacle_detector_node',
            name='obstacle_detector_node',
            output='screen'
        )
    ])
