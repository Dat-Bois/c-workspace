cmake_minimum_required(VERSION 3.9.1)

project(CMakeTest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES cmakeTest.c 
            lib/basicMath/basicMath.c
            lib/basicMath/basicMath.h)

add_executable(cmakeTest ${SOURCES})