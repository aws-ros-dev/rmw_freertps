// Copyright 2015 Open Source Robotics Foundation, Inc.
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

#ifndef ROSIDL_TYPESUPPORT_FREERTPS_CPP__MESSAGE_TYPE_SUPPORT_H_
#define ROSIDL_TYPESUPPORT_FREERTPS_CPP__MESSAGE_TYPE_SUPPORT_H_

typedef struct message_type_support_callbacks_t
{
  const char * package_name;
  const char * message_name;

  // Function to publish a ROS message with a given DDS data_writer
  // Returns NULL if the publish was successful, otherwise an error string.
  const char * (*publish)(
    void * frudp_pub, const void * ros_message);

  // Function to take a ROS message from a dds data reader
  // Returns NULL if the take was successful, otherwise an error string.
  // If no data is available to be taken, NULL is returned but taken will be set to false.
  const char * take(
    void * untyped_topic_reader,
    bool ignore_local_publications,
    void * untyped_ros_message,
    bool * taken);
} message_type_support_callbacks_t;

#endif  // ROSIDL_TYPESUPPORT_FREERTPS_CPP__MESSAGE_TYPE_SUPPORT_H_
