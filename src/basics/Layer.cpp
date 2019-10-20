#include <iostream>
#include "Layer.h"
#include "functional"
#include "Eigen/Dense"

Layer::Layer(int neuronCount, int inputCount, std::function<double(double)> activationFunction) {
    mInputCount = inputCount;
    mNeuronCount = neuronCount;
    mActivationFunction = std::move(activationFunction);

    // Initialize weights and bias to range 0 - 1
    // Eigen::MatrixXd::Random gives range(-1;1) therefore add 1 and divide by 2.

    mWeights = Eigen::MatrixXd::Random(neuronCount, inputCount);
    mWeights = (mWeights + Eigen::MatrixXd::Constant(neuronCount, inputCount, 1.0))* 0.5;

    mBias = Eigen::MatrixXd::Random(neuronCount, 1);
    mBias = (mBias + Eigen::MatrixXd::Constant(neuronCount, 1, 1.0))* 0.5;
}

Eigen::MatrixXd Layer::processInput(Eigen::MatrixXd inputMatrix) {
    // ForEach neuron (in mWeights)
    // 1. Sum products of weights and inputs.
    // 2. Add neuron bias.
    // 3. Use activation function.

    Eigen::MatrixXd output(mNeuronCount, 1);
    double neuronSum{};

    for (int neuronIndex = 0; neuronIndex < mNeuronCount; neuronIndex++) {

        neuronSum = 0;

        for (int inputPosition = 0; inputPosition < mInputCount; inputPosition++) {
            neuronSum += mWeights(neuronIndex, inputPosition) * inputMatrix(0, inputPosition) + mBias(neuronIndex, 0);
        }

        output(neuronIndex, 0) = mActivationFunction(neuronSum);
    }

    return output;
}
