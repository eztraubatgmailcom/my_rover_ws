from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    return LaunchDescription([
        # Static TF from base_link to gps_link
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='gps_tf',
            arguments=['0', '0', '0', '0', '0', '0', 'base_link', 'gps_link'],
            output='screen'
        ),

        # Static TF from base_link to imu_link
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='imu_tf',
            arguments=['0', '0', '0', '0', '0', '0', 'base_link', 'imu_link'],
            output='screen'
        ),

        # # Static TF from utm to odom
        # Node(
        #     package='tf2_ros',
        #     executable='static_transform_publisher',
        #     name='utm_to_odom_tf',
        #     arguments=['0', '0', '0', '0', '0', '0', 'utm', 'odom'],
        #     output='screen'
        # ),

        # UTM converter node (custom node)
        Node(
            package='gps_navigator_pkg',
            executable='gps_to_utm_node',
            name='gps_to_utm_node',
            output='screen'
        ),

        # EKF node
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_filter_node',
            output='screen',
            parameters=[
                PathJoinSubstitution([
                    FindPackageShare("my_rover_launch_pkg"),
                    "config",
                    "ekf_gps.yaml"
                ])
            ]
        )
    ])

