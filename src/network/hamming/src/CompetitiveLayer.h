#ifndef HAMMING_COMPETITIVELAYER_H
#define HAMMING_COMPETITIVELAYER_H

#include "Eigen/Dense"

class CompetitiveLayer {
public:
    CompetitiveLayer(int neuronCount); // Todo: Pass input and start processing or?

    // Number of neurons matches previous layer.
    // Weights matrix has a diagonal values that are in range 0 < n < 1 (One for each feature)

    Eigen::MatrixXd processInput(Eigen::MatrixXd inputMatrix);
private:
    Eigen::MatrixXd mWeights;
    void competeSingleIteration();
    bool hasConverged();
};


#endif //HAMMING_COMPETITIVELAYER_H
