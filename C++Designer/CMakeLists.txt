cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)

project(HotelManagementSystem)

# 加入头文件
include_directories(include)

# 加入cpp文件
file(GLOB_RECURSE src/*.cpp)

# 找到SDL库
find_package(SDL2 REQUIRED)

add_executable(HotelManagementSystem main.cpp)
