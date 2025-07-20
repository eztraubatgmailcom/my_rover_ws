import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    return LaunchDescription([
        # Node(
        #     package="tf2_ros",
        #     executable="static_transform_publisher",
        #     name="static_tf_imu_to_base",
        #     arguments=["0", "0", "0", "0", "0", "0", "base_link", "imu_link"],
        #     output="screen"
        # ),
        Node(
            package='gps_navigator_pkg',
            executable='read_nav_external',
            name='read_nav_external',
            output='screen'
        ),

        
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_filter_node',
            parameters=[os.path.join(get_package_share_directory('my_rover_launch_pkg'), 'config', 'ekf.yaml')],
            output='screen'
        )
    ])
