cmake_minimum_required(VERSION 3.9.1)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

project(App)

file(GLOB_RECURSE SOURCES "*.cpp")

add_definitions(-std=c++17 -g -Wall -Wextra)
# add_definitions(-std=c++17 -g0 -w)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/libraries)
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/libraries)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} pthread)