#ifndef NEURAL_NETWORK_BASENEURON_H
#define NEURAL_NETWORK_BASENEURON_H


#include <functional>

class SingleInputNeuron {
public:
    SingleInputNeuron();

    void scalarInput(float input);
    void activate();

    float getNeuronSum() const;

    void setWeight(float weigth);
    float getWeight() const;
    void setBias(float bias);
    float getBias() const;
    float getOutput() const;

    void setActivationFunction(std::function<float(float)> activationFunction);

    ~SingleInputNeuron();
private:
    float mInput;
    float mWeight;
    float mBias;
    float mOutput;
    std::function<float(float)> mActivationFunction;

};


#endif //NEURAL_NETWORK_BASENEURON_H
