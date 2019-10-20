## Notation:

    (a)     Lowercase letter - Scalar value
    (A)     Uppercase letter - Matrix or Vector

<br>

## Single input neuron

Defined by function:
    a = f(wp + b)
    
    w = weight
    p = input
    b = bias
    f = activation/transfer function.
    a = output
    
#### Example:

    std::function<float(float)> linearFunction = [](auto x) { return x; };

    SingleInputNeuron neuron;

    neuron.setWeight(0.44);
    neuron.setBias(0.73);
    neuron.scalarInput(0.78);

    std::cout << "NEURON SUM IS: " << neuron.getNeuronSum() << std::endl;

    neuron.setActivationFunction(linearFunction);
    neuron.activate();

    std::cout << "NEURON OUTPUT IS: " << neuron.getOutput() << std::endl;

> NEURON SUM IS: 1.0732\
  NEURON OUTPUT IS: 1.0732

<br>

## Multi input neuron

Defined by function:
    a = f(WP + b)
    
    WP = W(1,1) * P(1,1) + W(1,2) * P(1,2) +  ...  + W(1,n) * P(1,n)
    W = Vector of weights
    P = Vector of inputs
    b = bias
    f = activation/transfer function.
    a = output
    
#### Example:

    std::function<double(double)> sigmoid = [](auto x) { return 1 / (1 + exp(-x)); };

    Eigen::VectorXd vec1(5); vec1 << 0.34, 0.56, 0.78, 0.13, 0.19;
    Eigen::VectorXd vec2(5); vec2 << 0.68, 0.23, 0.24, 0.38, 0.16;

    MultiInputNeuron neuron;

    neuron.setWeightVector(vec1);
    neuron.setInputVector(vec2);
    neuron.setBias(0.73);

    std::cout << "NEURON SUM IS: " << neuron.getNeuronSum() << std::endl;

    neuron.setActivationFunction(sigmoid);
    neuron.activate();

    std::cout << "NEURON OUTPUT IS: " << neuron.getOutput() << std::endl;

> NEURON SUM IS: 0.627\
  NEURON OUTPUT IS: 0.651809

<br>
