import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

# navsat_config_path = os.path.join(
#     get_package_share_directory('my_rover_launch_pkg'),
#     'config',
#     'navsat_transform.yaml'
# )


def generate_launch_description():
    pkg_share = get_package_share_directory('my_rover_launch_pkg')
    return LaunchDescription([

        # Static Transform: base_link → imu_link
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            name="static_tf_imu_to_base",
            arguments=["0", "0", "0", "0", "0", "0", "base_link", "imu_link"],
            output="screen"
        ),

        # Static Transform: base_link → gps_link
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            name="static_tf_gps_to_base",
            arguments=["0", "0", "0", "0", "0", "0", "base_link", "gps_link"],
            output="screen"
        ),

        # EKF Filter
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_filter_node',
            parameters=[os.path.join(pkg_share, 'config', 'ekf.yaml')],
            output='screen'
        ),

        # WAS   >>>>    NavSat Transform Node
        #  Node(
        #      package='robot_localization',
        #      executable='navsat_transform_node',
        #      name='navsat_transform_node',
        #      parameters=[os.path.join(pkg_share, 'config', 'navsat_transform.yaml')],
        #      output='screen'
        # ),
        
        # NavSat Transform Node
        Node(
            package='robot_localization',
            executable='navsat_transform_node',
            name='navsat_transform_node',
            parameters=[os.path.join(pkg_share, 'config', 'navsat_transform.yaml')],
            remappings=[
                ('/fix', '/gps/fix'),
                ('/imu/data', '/imu/data_raw')
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
