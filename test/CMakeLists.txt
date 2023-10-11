
cmake_minimum_required(VERSION 3.0)

project(algocpp_math_test CXX)
set(CMAKE_CXX_STANDARD 20)

include_directories(./algocpp/includes/)

add_executable(apply apply.cpp)

target_link_libraries(apply gtest_main gtest)