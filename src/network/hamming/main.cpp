#include <iostream>
#include "src/CompetitiveLayer.h"
#include "src/FeedForwardLayer.h"
#include "Eigen/Dense"

int main() {

    int patternCount = 4;
    int featuresPerPattern = 4;

    Eigen::MatrixXd patterns(patternCount, featuresPerPattern);

    Eigen::VectorXd apple(featuresPerPattern);          apple << 1, 1, 0, 1;
    Eigen::VectorXd orange(featuresPerPattern);         orange << 1, 1, 1, 0;
    Eigen::VectorXd pear(featuresPerPattern);           pear << 0, 0, 0, 1;
    Eigen::VectorXd watermelon(featuresPerPattern);     watermelon << 1, 0, 0, 0;

    patterns << apple, orange, pear, watermelon;

    FeedForwardLayer feedForwardLayer(patterns);

    Eigen::VectorXd whatIsThisPattern(featuresPerPattern);
    whatIsThisPattern << 0, 1, 1, 1;

    Eigen::MatrixXd firstLayerOutput = feedForwardLayer.processInput(whatIsThisPattern);

    CompetitiveLayer competitiveLayer(patternCount);

    competitiveLayer.processInput(firstLayerOutput);


    return 0;
}