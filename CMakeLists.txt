cmake_minimum_required(VERSION 3.16)

project(optitrack-stream-client
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard")

include(cmake/InstallBasicPackageFiles.cmake)

add_subdirectory(stream_client)
add_subdirectory(client_lib)
add_subdirectory(apps)
