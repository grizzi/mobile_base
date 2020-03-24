#!/bin/bash

# Generate urdf and store it in a file
echo "Generating mobile_base.urdf in $(rospack find mobile_base_description)/resources ..."
rosrun xacro xacro -io $(rospack find mobile_base_description)/resources/mobile_base.urdf $(rospack find mobile_base_description)/urdf/mobile_base_standalone.urdf.xacro

echo "Done!"
