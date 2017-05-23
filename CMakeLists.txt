cmake_minimum_required(VERSION 3.7)
project(Calc)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp utils.cpp utils.h)
add_executable(Calc ${SOURCE_FILES})