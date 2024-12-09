cmake_minimum_required(VERSION 3.28)

project (bot)

set(CMAKE_CXX_STANDARD 20)

# Include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SRCS *.cppm)

set(TEST_APP balancer-bot)

add_library(${PROJECT_NAME} 
    ${SRCS})

target_sources(
    ${PROJECT_NAME}
    PUBLIC
    FILE_SET all_modules
    TYPE CXX_MODULES
    FILES ${SRCS})