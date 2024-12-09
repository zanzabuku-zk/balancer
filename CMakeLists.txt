cmake_minimum_required(VERSION 3.28)

project(balancer)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

include_directories(bot)
include_directories(net)

include(cmake/DownloadProject.cmake)

download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             release-1.10.0
                 UPDATE_DISCONNECTED 1
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()


#add_subdirectory(sandbox)
add_subdirectory(app)
add_subdirectory(net)
add_subdirectory(bot)
add_subdirectory(conf)
