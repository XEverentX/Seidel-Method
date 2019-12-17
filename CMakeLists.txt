cmake_minimum_required(VERSION 2.8)

project (seidel)

set(CMAKE_CXX_STANDARD 17)

set (SOURCE_EXE main.cpp)

add_subdirectory (algo)
add_subdirectory (application)

