cmake_minimum_required(VERSION 3.6)
project(BTrees)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp btrees.h btrees.cpp)
add_executable(BTrees ${SOURCE_FILES} btrees.cpp)