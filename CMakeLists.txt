cmake_minimum_required(VERSION 2.8)

project(ProgrammerTraining)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ansi -pedantic")
add_definitions("-std=c++11")

file(GLOB_RECURSE SOURCE_CODE *.cpp)

add_executable(math_helper ${SOURCE_CODE})