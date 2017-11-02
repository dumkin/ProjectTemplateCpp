cmake_minimum_required(VERSION 3.9.4)

set(CMAKE_C_COMPILER "clang-5.0")
set(CMAKE_CXX_COMPILER "clang++-5.0")

project(App)

file(GLOB_RECURSE SOURCES "*.cpp")

add_definitions(-std=c++2a -g -Wall -Wextra)
# add_definitions(-std=c++2a -g0 -w)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/libraries)
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/libraries)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} lua53 dl pthread)