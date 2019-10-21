#ifndef HAMMING_FEEDFORWARDLAYER_H
#define HAMMING_FEEDFORWARDLAYER_H


#include <functional>
#include "Eigen/Dense"

class FeedForwardLayer {
public:
    FeedForwardLayer(Eigen::MatrixXd patterns);

    Eigen::MatrixXd processInput(Eigen::MatrixXd inputMatrix);

private:
    Eigen::MatrixXd mWeights;
    Eigen::MatrixXd mBias;
    std::function<double(double)> mActivationFunction;
};


#endif //HAMMING_FEEDFORWARDLAYER_H
