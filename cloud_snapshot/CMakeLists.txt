cmake_minimum_required(VERSION 3.5.1)
project(cloud_snapshot)

find_package(catkin REQUIRED COMPONENTS roscpp cloud_snapshot_msgs sensor_msgs)

catkin_package(
CATKIN_DEPENDS roscpp cloud_snapshot_msgs sensor_msgs
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
)

add_executable(cloud_snapshot_node src/cloud_snapshot_server_node.cpp
  src/cloud_snapshot_server.cpp)

target_link_libraries(cloud_snapshot_node ${catkin_LIBRARIES})

install(TARGETS cloud_snapshot_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
