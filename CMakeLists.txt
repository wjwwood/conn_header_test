cmake_minimum_required(VERSION 2.8.3)
project(conn_header_test)

find_package(catkin REQUIRED COMPONENTS std_msgs roscpp)

# catkin_python_setup()

catkin_package()

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})

install(PROGRAMS src/talker.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(TARGETS talker listener
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
