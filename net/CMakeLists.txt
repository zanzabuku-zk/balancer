cmake_minimum_required(VERSION 3.10)

project (net)

include(../cmake/DownloadProject.cmake)

download_project(PROJ                websocketpp
                 GIT_REPOSITORY      https://github.com/zaphoyd/websocketpp.git
                 GIT_TAG             0.8.2
)

# Include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SRCS *.cppm)

set(TEST_APP ${PROJECT_NAME}_tests)

add_library(${PROJECT_NAME} 
    ${SRCS})

target_sources(
    ${PROJECT_NAME}
    PUBLIC
    FILE_SET all_modules
    TYPE CXX_MODULES
    FILES ${SRCS})
