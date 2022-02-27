cmake_minimum_required(VERSION 3.21)
project(mavlink_test)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE MAV_SRC "dji_mavlink/*.cpp" "dji_mavlink/*.c")
add_executable(mavlink_test main.cpp ${MAV_SRC})
target_link_libraries(mavlink_test pthread)
