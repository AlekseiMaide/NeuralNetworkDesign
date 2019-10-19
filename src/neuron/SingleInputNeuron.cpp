#include "SingleInputNeuron.h"
#include <utility>

SingleInputNeuron::SingleInputNeuron()
        : mWeight(0.5),
          mBias(0.64) {

    // Todo: Generate a random weight?
}

float SingleInputNeuron::getWeight() const {
    return mWeight;
}

void SingleInputNeuron::setWeight(float weigth) {
    mWeight = weigth;
}

void SingleInputNeuron::setBias(float bias) {
    mBias = bias;
}

float SingleInputNeuron::getBias() const {
    return mBias;
}

float SingleInputNeuron::getOutput() const {
    return mOutput;
}

void SingleInputNeuron::activate() {
    mOutput = mActivationFunction(getNeuronSum());
}

float SingleInputNeuron::getNeuronSum() const {
    return mWeight * mInput + mBias;
}

void SingleInputNeuron::scalarInput(float input) {
    mInput = input;
}

void SingleInputNeuron::setActivationFunction(std::function<float(float)> activationFunction) {
    mActivationFunction = std::move(activationFunction);
}

SingleInputNeuron::~SingleInputNeuron() = default;
