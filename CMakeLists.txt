cmake_minimum_required(VERSION 3.26)
project(ProjectZ C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

find_package(SDL3 REQUIRED)

add_executable(ProjectZ)

target_sources(ProjectZ
PRIVATE
    src/main.cpp
)

target_link_libraries(ProjectZ SDL3::SDL3)