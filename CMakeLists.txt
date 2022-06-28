cmake_minimum_required(VERSION 3.8)
project("raytracing")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(raytracing src/main.cc src/ray.hh src/ray.cc src/vec.hh src/vec.cc)