from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'my_rover_launch_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        # Register package XML & resource index
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),

        # ✅ Install all *.launch.py files under launch/
        (os.path.join('share', package_name, 'launch'),
         glob('launch/*.launch.py')),

        # ✅ Install config files (*.yaml) under config/
        (os.path.join('share', package_name, 'config'),
         glob('config/*.yaml')),
        
        (os.path.join('share', package_name, 'launch'),
        glob(os.path.join('launch', '*launch.py'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='rover',
    maintainer_email='rover@todo.todo',
    description='Launch and config for my MITI Rover project',
    license='TODO: License declaration',
    tests_require=['pytest'],
    
    entry_points={
        'console_scripts': [
            'static_tf_gps = my_rover_launch_pkg.static_tf_gps:main',
        ],
    }
)
