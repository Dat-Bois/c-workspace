cmake_minimum_required(VERSION 3.9.1)

project(CMakeTest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES cmakeTest.c)

if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    add_definitions(-DCMAKEMACROSAMPLE="Apple MacOS")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    add_definitions(-DCMAKEMACROSAMPLE="Windows PC")
else()
    add_definitions(-DCMAKEMACROSAMPLE="Generic")
endif()

add_executable(cmakeTest ${SOURCES})

add_subdirectory(lib/cJSON)
target_link_libraries(cmakeTest PUBLIC cjson)
target_include_directories(cmakeTest PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib/cJSON"
                          )