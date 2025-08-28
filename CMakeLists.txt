cmake_minimum_required(VERSION 3.26)
project(ProjectZ C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(ProjectZ)

target_sources(ProjectZ
PRIVATE
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Mob.cpp
    src/Spawner.cpp
)

target_link_libraries(ProjectZ
SDL3_ttf::SDL3_ttf 
SDL3_image::SDL3_image
SDL3::SDL3)