cmake_minimum_required(VERSION 3.14)

project(naive_redis_module)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include)

set(MODULE_SRC ${CMAKE_SOURCE_DIR}/src/rmod.cpp)
add_library(rmod_module SHARED ${MODULE_SRC})