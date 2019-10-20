#ifndef NEURALNETWORKDESIGN_LAYER_H
#define NEURALNETWORKDESIGN_LAYER_H

#include "Eigen/Dense"


class Layer {
public:
    Layer(int neuronCount, int inputCount, std::function<double(double)> activationFunction);

    Eigen::MatrixXd processInput(Eigen::MatrixXd inputMatrix);

private:
    int mInputCount;
    int mNeuronCount;

    Eigen::MatrixXd mWeights;
    Eigen::MatrixXd mBias;
    std::function<double(double)> mActivationFunction;
};


#endif //NEURALNETWORKDESIGN_LAYER_H
