import pyrealsense2 as rs
from main_debug import dectrun
import numpy as np
import torch

pipeline = rs.pipeline()
config = rs.config()
config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 60)
config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 60)
# Start streaming
pipeline.start(config)
try:
    while True:
        # Wait for a coherent pair of frames: depth and color
        frames = pipeline.wait_for_frames()
        depth_frame = frames.get_depth_frame()
        color_frame = frames.get_color_frame()
        if not depth_frame or not color_frame:
            continue
        # box_dist, obj_class = dectrun(depth_frame, color_frame)
        # minimal_publisher.message = str(dectrun(depth_frame, color_frame))
        # rclpy.spin(minimal_publisher)
finally:
    # Stop streaming
    pipeline.stop()