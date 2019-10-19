#ifndef NEURAL_NETWORK_MULTIINPUTNEURON_H
#define NEURAL_NETWORK_MULTIINPUTNEURON_H


#include <functional>
#include <Eigen/Dense>

class MultiInputNeuron {
public:
    MultiInputNeuron();

    void setInputVector(Eigen::VectorXd input);
    void activate();

    double getNeuronSum() const;

    void setWeightVector(Eigen::VectorXd weights);
    Eigen::VectorXd getWeightVector() const;
    void setBias(double bias);
    double getBias() const;
    double getOutput() const;

    void setActivationFunction(std::function<double(double)> activationFunction);

    ~MultiInputNeuron();
private:
    Eigen::VectorXd mInputVector;
    Eigen::VectorXd mWeightVector;
    double mBias;
    double mOutput;
    std::function<double(double)> mActivationFunction;

};


#endif //NEURAL_NETWORK_MULTIINPUTNEURON_H
