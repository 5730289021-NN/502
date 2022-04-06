from setuptools import setup

package_name = 'detection'
submodules = 'detection/pyrealsense2'
submodules = 'detection/detection_lib'
setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name,submodules],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='amejiyo',
    maintainer_email='pakapak9848@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        	'detect_talker = detection.fine_detect_publisher:main',
        ],
    },
)
