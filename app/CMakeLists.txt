cmake_minimum_required(VERSION 3.28)

project (app)

set(CMAKE_CXX_STANDARD 20)

# Include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SRCS *.cpp)

add_executable(balancer-bot 
    ${SRCS})

target_link_libraries(
    balancer-bot 
    PUBLIC bot)
