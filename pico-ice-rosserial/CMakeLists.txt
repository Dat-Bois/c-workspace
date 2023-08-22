cmake_minimum_required(VERSION 3.12)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) #output executable to bin folder

#check system (doesn't matter right now)
if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    add_definitions(-DSYSTEMTYPE="Apple MacOS")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    add_definitions(-DSYSTEMTYPE="Windows PC")
else()
    add_definitions(-DSYSTEMTYPE="Linux")
endif()

#checking to see if pico-sdk exists
if(EXISTS "${CMAKE_SOURCE_DIR}/lib/pico-sdk/external")
    #inits
    set(PICO_PATH ${CMAKE_SOURCE_DIR}/lib/pico-sdk)
    set(ENV{PICO_SDK_PATH} ${PICO_PATH})
    include(${PICO_PATH}/external/pico_sdk_import.cmake)
    #helper stuff
    message(STATUS "pico-sdk found at:")
    message(STATUS ${PICO_PATH})
    set(FOUND_PICO_SDK TRUE)
    add_definitions(-DFOUND_PICO_SDK=${FOUND_PICO_SDK}) #lets c program know if pico-sdk was found
else()
    message(STATUS "pico-sdk not found ; not building for pico")
    set(FOUND_PICO_SDK FALSE)
endif()

#----------------------------------
project(pico_ros_serial C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
# setup executable
set(SOURCES main.c)
add_executable(pico_ros_serial ${SOURCES})
set(ENABLE_CJSON_TEST off)
add_subdirectory(lib/cJSON)
target_include_directories(pico_ros_serial PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/lib/cJSON")

if(FOUND_PICO_SDK)
    pico_sdk_init()
    
    SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ffunction-sections -fdata-sections")

    # Configure Pico
    pico_enable_stdio_usb(pico_ros_serial 1)
    pico_enable_stdio_uart(pico_ros_serial 0)
    add_compile_definitions(PICO_UART_ENABLE_CRLF_SUPPORT=0)
    add_compile_definitions(PICO_STDIO_ENABLE_CRLF_SUPPORT=0)
    add_compile_definitions(PICO_STDIO_DEFAULT_CRLF=0)
    add_compile_definitions(PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS=5000)

    # Generate UF2
    pico_add_extra_outputs(pico_ros_serial)
    target_link_libraries(pico_ros_serial PUBLIC cjson pico_stdlib)
else()
    target_link_libraries(pico_ros_serial PUBLIC cjson)
endif()