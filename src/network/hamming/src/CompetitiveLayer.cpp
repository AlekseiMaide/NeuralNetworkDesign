#include <iostream>
#include "CompetitiveLayer.h"
#include "Eigen/Dense"
#include "algorithm"

CompetitiveLayer::CompetitiveLayer(int neuronCount) {
    Eigen::MatrixXd identityMatrix = Eigen::MatrixXd::Identity(neuronCount, neuronCount);
    mWeights = Eigen::MatrixXd::Ones(neuronCount, neuronCount);
    mWeights -= Eigen::MatrixXd::Ones(neuronCount, neuronCount) * 1.25;
    mWeights += identityMatrix * 1.5;

    std::cout << "Recurrent layer weigths:\n " << mWeights << std::endl;

    mActivationFunction = [](double x) { return std::fmax(0, x); };
}

Eigen::MatrixXd CompetitiveLayer::processInput(Eigen::MatrixXd inputMatrix) {

    Eigen::MatrixXd output;
    Eigen::MatrixXd prevOutput;

    int recurenceNumber = 0;

    while (true) {

        if (recurenceNumber == 0) {
            output = Eigen::Product(mWeights, inputMatrix).unaryExpr(mActivationFunction);

            std::cout << "Recurrence: " << recurenceNumber << " Output is: \n" << output << std::endl;
        } else {
            prevOutput = output;
            output = Eigen::Product(mWeights, prevOutput).unaryExpr(mActivationFunction);

            std::cout << "Recurrence: " << recurenceNumber << " Output is: \n" << output << std::endl;

            if (prevOutput.isApprox(output) || hasConverged(output)) return output;
        }

        recurenceNumber++;
    }
}

bool CompetitiveLayer::hasConverged(Eigen::MatrixXd matrix) {
    int rowCount = matrix.rows();
    int colCount = matrix.cols();

    int nonZeroCount = 0;

    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (matrix(i, j) != 0) {
                nonZeroCount++;
            }
        }
    }

    return nonZeroCount == 1;
}
