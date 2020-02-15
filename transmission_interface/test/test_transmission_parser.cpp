// Copyright 2020 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "transmission_interface/transmission_parser.hpp"

class TestTransmissionParser : public ::testing::Test
{
public:
  void SetUp() override
  {
    urdf_xml_ =
      R"(
    <?xml version="1.0" ?>
<!-- =================================================================================== -->
<!-- |    This document was autogenerated by xacro from single_rrbot.urdf.xacro        | -->
<!-- |    EDITING THIS FILE BY HAND IS NOT RECOMMENDED                                 | -->
<!-- =================================================================================== -->
<robot name="single_rrbot" xmlns:xacro="http://www.ros.org/wiki/xacro">
  <!-- Build your comprehensive robot -->
  <link name="world"/>
  <gazebo reference="world">
    <static>true</static>
  </gazebo>
  <joint name="single_rrbot_fixed" type="fixed">
    <origin rpy="0 0 0" xyz="0 0 0"/>
    <parent link="world"/>
    <child link="single_rrbot_link1"/>
  </joint>
  <link name="single_rrbot_link1">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <geometry>
        <box size="0.1 0.1 2"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <geometry>
        <box size="0.1 0.1 2"/>
      </geometry>
      <material name="RRBOT/orange"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="single_rrbot_joint1" type="continuous">
    <parent link="single_rrbot_link1"/>
    <child link="single_rrbot_link2"/>
    <origin rpy="0 0 0" xyz="0 0.1 1.95"/>
    <axis xyz="0 1 0"/>
    <dynamics damping="0.7"/>
  </joint>
  <link name="single_rrbot_link2">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
      <material name="RRBOT/black"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="single_rrbot_joint2" type="continuous">
    <parent link="single_rrbot_link2"/>
    <child link="single_rrbot_link3"/>
    <origin rpy="0 0 0" xyz="0 0.1 0.9"/>
    <axis xyz="0 1 0"/>
    <dynamics damping="0.7"/>
  </joint>
  <link name="single_rrbot_link3">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
      <material name="RRBOT/orange"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="single_rrbot_hokuyo_joint" type="fixed">
    <axis xyz="0 1 0"/>
    <origin rpy="0 0 0" xyz="0 0 0.975"/>
    <parent link="single_rrbot_link3"/>
    <child link="single_rrbot_hokuyo_link"/>
  </joint>
  <link name="single_rrbot_hokuyo_link">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.1 0.1 0.1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.1 0.1 0.1"/>
      </geometry>
    </visual>
    <inertial>
      <mass value="1e-5"/>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <inertia ixx="1e-6" ixy="0" ixz="0" iyy="1e-6" iyz="0" izz="1e-6"/>
    </inertial>
  </link>
  <joint name="single_rrbot_camera_joint" type="fixed">
    <axis xyz="0 1 0"/>
    <origin rpy="0 0 0" xyz="0.05 0 0.9"/>
    <parent link="single_rrbot_link3"/>
    <child link="single_rrbot_camera_link"/>
  </joint>
  <link name="single_rrbot_camera_link">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.05 0.05 0.05"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.05 0.05 0.05"/>
      </geometry>
      <material name="RRBOT/red"/>
    </visual>
    <inertial>
      <mass value="1e-5"/>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <inertia ixx="1e-6" ixy="0" ixz="0" iyy="1e-6" iyz="0" izz="1e-6"/>
    </inertial>
  </link>
  <transmission name="single_rrbot_tran1">
    <type>transmission_interface/SimpleTransmission</type>
    <joint name="single_rrbot_joint1">
      <hardwareInterface>PositionJointInterface</hardwareInterface>
    </joint>
    <actuator name="single_rrbot_motor1">
      <mechanicalReduction>1</mechanicalReduction>
    </actuator>
  </transmission>
  <transmission name="single_rrbot_tran2">
    <type>transmission_interface/SimpleTransmission</type>
    <joint name="single_rrbot_joint2">
      <hardwareInterface>PositionJointInterface</hardwareInterface>
    </joint>
    <actuator name="single_rrbot_motor2">
      <mechanicalReduction>1</mechanicalReduction>
    </actuator>
  </transmission>
  <gazebo reference="single_rrbot_link1">
    <material>Gazebo/Orange</material>
  </gazebo>
  <gazebo reference="single_rrbot_link2">
    <mu1>0.2</mu1>
    <mu2>0.2</mu2>
    <material>Gazebo/Black</material>
  </gazebo>
  <gazebo reference="single_rrbot_link3">
    <mu1>0.2</mu1>
    <mu2>0.2</mu2>
    <material>Gazebo/Orange</material>
  </gazebo>
  <gazebo>
    <plugin name="gazebo_ros_control" filename="libgazebo_ros_control.so">
    </plugin>
  </gazebo>
</robot>
  )";

    wrong_urdf_xml_ =
      R"(
    <?xml version="1.0" ?>
<!-- =================================================================================== -->
<!-- |    This document was autogenerated by xacro from single_rrbot.urdf.xacro        | -->
<!-- |    EDITING THIS FILE BY HAND IS NOT RECOMMENDED                                 | -->
<!-- =================================================================================== -->
<robot name="single_rrbot" xmlns:xacro="http://www.ros.org/wiki/xacro">
  <!-- Build your comprehensive robot -->
  <link name="world"/>
  <gazebo reference="world">
    <static>true</static>
  </gazebo>
  <joint name="single_rrbot_fixed" type="fixed">
    <origin rpy="0 0 0" xyz="0 0 0"/>
    <parent link="world"/>
    <child link="single_rrbot_link1"/>
  </joint>
  <link name="single_rrbot_link1">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <geometry>
        <box size="0.1 0.1 2"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <geometry>
        <box size="0.1 0.1 2"/>
      </geometry>
      <material name="RRBOT/orange"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 1.0"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="single_rrbot_joint1" type="continuous">
    <parent link="single_rrbot_link1"/>
    <child link="single_rrbot_link2"/>
    <origin rpy="0 0 0" xyz="0 0.1 1.95"/>
    <axis xyz="0 1 0"/>
    <dynamics damping="0.7"/>
  </joint>
  <link name="single_rrbot_link2">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
      <material name="RRBOT/black"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="single_rrbot_joint2" type="continuous">
    <parent link="single_rrbot_link2"/>
    <child link="single_rrbot_link3"/>
    <origin rpy="0 0 0" xyz="0 0.1 0.9"/>
    <axis xyz="0 1 0"/>
    <dynamics damping="0.7"/>
  </joint>
  <link name="single_rrbot_link3">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <geometry>
        <box size="0.1 0.1 1"/>
      </geometry>
      <material name="RRBOT/orange"/>
    </visual>
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 0.45"/>
      <mass value="1"/>
      <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
    </inertial>
  </link>
  <joint name="single_rrbot_hokuyo_joint" type="fixed">
    <axis xyz="0 1 0"/>
    <origin rpy="0 0 0" xyz="0 0 0.975"/>
    <parent link="single_rrbot_link3"/>
    <child link="single_rrbot_hokuyo_link"/>
  </joint>
  <link name="single_rrbot_hokuyo_link">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.1 0.1 0.1"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.1 0.1 0.1"/>
      </geometry>
    </visual>
    <inertial>
      <mass value="1e-5"/>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <inertia ixx="1e-6" ixy="0" ixz="0" iyy="1e-6" iyz="0" izz="1e-6"/>
    </inertial>
  </link>
  <joint name="single_rrbot_camera_joint" type="fixed">
    <axis xyz="0 1 0"/>
    <origin rpy="0 0 0" xyz="0.05 0 0.9"/>
    <parent link="single_rrbot_link3"/>
    <child link="single_rrbot_camera_link"/>
  </joint>
  <link name="single_rrbot_camera_link">
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.05 0.05 0.05"/>
      </geometry>
    </collision>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <box size="0.05 0.05 0.05"/>
      </geometry>
      <material name="RRBOT/red"/>
    </visual>
    <inertial>
      <mass value="1e-5"/>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <inertia ixx="1e-6" ixy="0" ixz="0" iyy="1e-6" iyz="0" izz="1e-6"/>
    </inertial>
  </link>
  <transmission name="single_rrbot_tran1">
    <type>transmission_interface/SimpleTransmission</type>
    <actuator name="single_rrbot_motor1">
      <mechanicalReduction>1</mechanicalReduction>
    </actuator>
  </transmission>
  <gazebo reference="single_rrbot_link1">
    <material>Gazebo/Orange</material>
  </gazebo>
  <gazebo reference="single_rrbot_link2">
    <mu1>0.2</mu1>
    <mu2>0.2</mu2>
    <material>Gazebo/Black</material>
  </gazebo>
  <gazebo reference="single_rrbot_link3">
    <mu1>0.2</mu1>
    <mu2>0.2</mu2>
    <material>Gazebo/Orange</material>
  </gazebo>
  <gazebo>
    <plugin name="gazebo_ros_control" filename="libgazebo_ros_control.so">
    </plugin>
  </gazebo>
</robot>
  )";
  }

  std::string urdf_xml_;
  std::string wrong_urdf_xml_;
};

TEST_F(TestTransmissionParser, parse_transmission_info) {
  std::vector<transmission_interface::TransmissionInfo> transmissions;
  transmission_interface::TransmissionParser parser(TestTransmissionParser::urdf_xml_);
  auto ret = parser.parse_transmission_info(transmissions);

  ASSERT_TRUE(ret);
  ASSERT_EQ(2u, transmissions.size());
  EXPECT_TRUE(parser.get_error_msg().empty()) << parser.get_error_msg();
  EXPECT_EQ("single_rrbot_joint1", transmissions[0].joint_name);
  EXPECT_EQ(
    transmission_interface::JointControlType::POSITION, transmissions[0].joint_control_type);
  EXPECT_EQ("single_rrbot_joint2", transmissions[1].joint_name);
  EXPECT_EQ(
    transmission_interface::JointControlType::POSITION, transmissions[1].joint_control_type);
}

TEST_F(TestTransmissionParser, empty_urdf) {
  std::vector<transmission_interface::TransmissionInfo> transmissions;
  ASSERT_THROW(
    transmission_interface::TransmissionParser parser(""), std::runtime_error);
}

TEST_F(TestTransmissionParser, wrong_urdf) {
  std::vector<transmission_interface::TransmissionInfo> transmissions;
  transmission_interface::TransmissionParser parser(TestTransmissionParser::wrong_urdf_xml_);
  auto ret = parser.parse_transmission_info(transmissions);

  ASSERT_FALSE(ret);
  EXPECT_FALSE(parser.get_error_msg().empty()) << parser.get_error_msg();
}