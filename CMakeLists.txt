cmake_minimum_required(VERSION 3.16)
project(templated_lists)

set(CMAKE_CXX_STANDARD 14)

#add_executable(templated_lists main.cpp)
set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR})
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/include/*.h)
file(GLOB_RECURSE HEADERS ${PROJECT_SOURCES_DIR}/src/*.cpp)

add_executable(templated_lists ${HEADERS} ${SOURCES})

include_directories(${PROJECT_HEADERS_DIR})