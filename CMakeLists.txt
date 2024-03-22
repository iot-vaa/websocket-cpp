cmake_minimum_required(VERSION 3.0)

project(websocket)

find_package(Boost REQUIRED COMPONENTS thread)  # Adjust COMPONENTS as needed

include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-v -pthread")
add_executable(main main.cpp)

target_link_libraries(main PUBLIC Boost::thread)
