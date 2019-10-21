cmake_minimum_required(VERSION 3.10)
project(NeuralNetworkDesign)

set(CMAKE_CXX_STANDARD 17)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories(includes)

add_executable(NeuralNetworkDesign main.cpp
        src/basics/SingleInputNeuron.cpp
        src/basics/SingleInputNeuron.h
        src/basics/MultiInputNeuron.cpp
        src/basics/MultiInputNeuron.h
        src/basics/Layer.cpp
        src/basics/Layer.h
        src/activation_functions/ActivationFunction.cpp
        src/activation_functions/ActivationFunction.h
)
target_compile_definitions(NeuralNetworkDesign PUBLIC VERSION=0.1)
