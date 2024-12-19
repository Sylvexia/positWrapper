cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(UNIVERSAL_INCLUDE /home/sylvex/universal/include)

# Set the project name
project(positWrapper)

find_package(pybind11 REQUIRED)

# Add the library
add_library(positWrapper SHARED positWrapperC.cpp)
add_library(positWrapperPy MODULE positWrapperPybind.cpp)

# Specify include directories
target_include_directories(positWrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(positWrapper PUBLIC ${UNIVERSAL_INCLUDE})
target_include_directories(positWrapperPy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(positWrapperPy PRIVATE ${UNIVERSAL_INCLUDE})

add_executable(test test.cpp)

target_link_libraries(test positWrapper)
target_link_libraries(positWrapperPy pybind11::module)