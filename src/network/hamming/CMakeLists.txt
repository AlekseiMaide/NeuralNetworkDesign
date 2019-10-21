cmake_minimum_required(VERSION 3.10)
project(hamming)

set(CMAKE_CXX_STANDARD 17)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories(includes)

add_executable(hamming main.cpp
        src/CompetitiveLayer.cpp
        src/CompetitiveLayer.h
        src/FeedForwardLayer.cpp
        src/FeedForwardLayer.h
        src/Network.cpp
        src/Network.h)