cmake_minimum_required(VERSION 3.16)
project(dhpr_vector VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(dhpr_vector INTERFACE)

target_include_directories(dhpr_vector
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

enable_testing()
add_subdirectory(tests)