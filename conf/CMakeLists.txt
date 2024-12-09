cmake_minimum_required(VERSION 3.28)

project (conf)

set(CMAKE_CXX_STANDARD 20)

# Include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(../cmake/DownloadProject.cmake)

download_project(PROJ                rapidjson
                 GIT_REPOSITORY      https://github.com/Tencent/rapidjson.git
                 GIT_TAG             v1.1.0
)

include_directories(${rapidjson_SOURCE_DIR} ${rapidjson_BINARY_DIR})

file(GLOB SRCS *.cppm)

add_library(${PROJECT_NAME} 
    ${SRCS})

    target_sources(
    ${PROJECT_NAME}
    PUBLIC
    FILE_SET all_modules
    TYPE CXX_MODULES
    FILES ${SRCS})