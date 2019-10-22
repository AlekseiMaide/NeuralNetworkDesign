#include "FeedForwardLayer.h"
#include <iostream>
#include "functional"
#include "Eigen/Dense"

FeedForwardLayer::FeedForwardLayer(Eigen::MatrixXd patterns) {
    mWeights = patterns;
    mActivationFunction = [](auto x) { return x; }; // Linear function
    mBias = Eigen::MatrixXd::Constant(patterns.rows(), 1, patterns.cols());

    std::cout << "FeedForward layer weigths:\n " << mWeights << std::endl;
    std::cout << "FeedForward layer bias:\n " << mBias << std::endl;
}

Eigen::MatrixXd FeedForwardLayer::processInput(Eigen::MatrixXd inputMatrix) {
    // ForEach neuron (in mWeights)
    // 1. Sum products of weights and inputs.
    // 2. Add neuron bias.
    // 3. Use activation function.

    auto neuronCount = (int)mWeights.rows();
    auto featureCount = (int)mWeights.cols();

    Eigen::MatrixXd output(neuronCount, 1);

    output = Eigen::Product(mWeights.transpose(), inputMatrix);
    output += mBias;
    output = output.unaryExpr(mActivationFunction);

    std::cout << "FeedForward layer output:\n " << output << std::endl;

    return output;
}