#include "FeedForwardLayer.h"
#include <iostream>
#include "functional"
#include "Eigen/Dense"

FeedForwardLayer::FeedForwardLayer(Eigen::MatrixXd patterns) {
    mWeights = patterns;
    mActivationFunction = [](auto x) { return x; }; // Linear function
    mBias = Eigen::MatrixXd::Constant(patterns.rows(), 1, patterns.cols());
}

Eigen::MatrixXd FeedForwardLayer::processInput(Eigen::MatrixXd inputMatrix) {
    // ForEach neuron (in mWeights)
    // 1. Sum products of weights and inputs.
    // 2. Add neuron bias.
    // 3. Use activation function.

    auto neuronCount = (int)mWeights.rows();
    auto featureCount = (int)mWeights.cols();

    Eigen::MatrixXd output(neuronCount, 1);
    double neuronSum{};

    for (int neuronIndex = 0; neuronIndex < neuronCount; neuronIndex++) {

        neuronSum = 0;

        for (int featurePosition = 0; featurePosition < featureCount; featurePosition++) {
            neuronSum += mWeights(neuronIndex, featurePosition) * inputMatrix(0, featurePosition) + mBias(neuronIndex, 0);
        }

        output(neuronIndex, 0) = mActivationFunction(neuronSum);
    }

    return output;
}