#ifndef HAMMING_COMPETITIVELAYER_H
#define HAMMING_COMPETITIVELAYER_H

#include "Eigen/Dense"

class CompetitiveLayer {
public:
    CompetitiveLayer(int neuronCount);

    Eigen::MatrixXd processInput(Eigen::MatrixXd inputMatrix);
private:
    Eigen::MatrixXd mWeights;
    std::function<double(double)> mActivationFunction;

    bool hasConverged(Eigen::MatrixXd matrix);
};


#endif //HAMMING_COMPETITIVELAYER_H
