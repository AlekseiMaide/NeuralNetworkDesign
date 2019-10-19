#include "MultiInputNeuron.h"
#include <utility>

MultiInputNeuron::MultiInputNeuron() = default;

void MultiInputNeuron::setInputVector(Eigen::VectorXd input) {
    mInputVector = std::move(input);
}

void MultiInputNeuron::activate() {
    mOutput = mActivationFunction(getNeuronSum());
}

double MultiInputNeuron::getNeuronSum() const {

    Eigen::VectorXd product = mWeightVector.cwiseProduct(mInputVector);

    return product.sum();
}

void MultiInputNeuron::setWeightVector(Eigen::VectorXd weights) {
    mWeightVector = std::move(weights);
}

Eigen::VectorXd MultiInputNeuron::getWeightVector() const {
    return mWeightVector;
}

void MultiInputNeuron::setBias(double bias) {
    mBias = bias;
}

double MultiInputNeuron::getBias() const {
    return mBias;
}

double MultiInputNeuron::getOutput() const {
    return mOutput;
}

void MultiInputNeuron::setActivationFunction(std::function<double(double)> activationFunction) {
    mActivationFunction = std::move(activationFunction);
}

MultiInputNeuron::~MultiInputNeuron() = default;
