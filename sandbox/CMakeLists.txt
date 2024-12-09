cmake_minimum_required(VERSION 3.10)

project (sandbox)

include(CTest)

# Include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SRCS *.cpp)

set(TEST_APP ${PROJECT_NAME}_tests)

add_executable(${PROJECT_NAME} 
    ${SRCS})
