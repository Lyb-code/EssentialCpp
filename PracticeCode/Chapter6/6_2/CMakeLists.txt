# cmake 的版本要求
cmake_minimum_required(VERSION 3.14)
# 项目名称
project(6_2)
# 设置debug模式
set(CMAKE_BUILD_TYPE "Debug")
# 设置源文件根目录，并设置别名为DIR_ROOT
aux_source_directory(. DIR_ROOT)
# 设置CPP版本标准
set(CMAKE_CXX_STANDARD 11)
# 项目包含哪些文件
add_executable(${PROJECT_NAME} Matrix.cpp main.cpp)