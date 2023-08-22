cmake_minimum_required(VERSION 3.9.1)

project(main)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES main.c)

if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    add_definitions(-DCMAKEMACROSAMPLE="Apple MacOS")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    add_definitions(-DCMAKEMACROSAMPLE="Windows PC")
else()
    add_definitions(-DCMAKEMACROSAMPLE="Linux")
endif()

add_executable(main ${SOURCES})

add_subdirectory(lib/cJSON)
target_link_libraries(main PUBLIC cjson)
target_include_directories(main PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib/cJSON"
                          )