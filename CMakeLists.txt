cmake_minimum_required(VERSION 3.5)
project(ACM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES

  SCC/4612.cpp)

add_executable(ACM ${SOURCE_FILES})