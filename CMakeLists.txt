cmake_minimum_required(VERSION 3.16)
project(templated_lists)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")

include(CMake/googletest.cmake)
fetch_googletest(${PROJECT_SOURCE_DIR}/CMake ${PROJECT_BINARY_DIR}/googletest)
enable_testing()
add_subdirectory(library)

add_subdirectory(src)

#set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR})
#set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR})
#
#file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/include/*.h)
#file(GLOB_RECURSE HEADERS ${PROJECT_SOURCES_DIR}/src/*.cpp)
#
#add_executable(templated_lists ${HEADERS} ${SOURCES})
#
#include_directories(${PROJECT_HEADERS_DIR})