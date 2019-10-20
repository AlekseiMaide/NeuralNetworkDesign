cmake_minimum_required(VERSION 3.10)
project(NeuralNetworkDesign)

set(CMAKE_CXX_STANDARD 17)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories(includes)

add_executable(NeuralNetworkDesign main.cpp src/neuron/SingleInputNeuron.cpp src/neuron/SingleInputNeuron.h src/neuron/MultiInputNeuron.cpp src/neuron/MultiInputNeuron.h src/activation_functions/ActivationFunction.cpp src/activation_functions/ActivationFunction.h src/layer/Layer.cpp src/layer/Layer.h)
target_compile_definitions(NeuralNetworkDesign PUBLIC VERSION=0.1)
