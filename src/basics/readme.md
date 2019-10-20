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

## Single Layer

Defined by function:\
    A = f(WP + B)
    
    WP + B = W(1,1) * P(1,1) + B(1,1) + W(1,2) * P(1,2) + B(1,2) +  ...  + W(1,n) * P(1,n) + B(1,n)
    W = Matrix of weights
    P = Matrix of inputs
    B = Matrix of neuron biases
    f = activation/transfer function.
    A = Output Matrix
    
W matrix rows represent neurons and columns represent the weights for given inputs which means that P (and B) matrix columns match those accordingly.
    
#### Example:

Initialize a layer of 5 neurons and 2 inputs and sigmoid function as activation.\
Layer weights and biases get assigned randomly.\
Pass a 1x2 matrix as input to layer for processing.\
The output is 5x1 matrix where each row represents an output of a single neruon.
    
    std::function<double(double)> sigmoid = [](auto x) { return 1 / (1 + exp(-x)); };

    Layer layer(5, 2, sigmoid);
    Eigen::MatrixXd inputMatrix = Eigen::MatrixXd::Random(1, 2);

    std::cout << "LAYER OUTPUT IS:\n" << layer.processInput(inputMatrix) << std::endl;

> LAYER OUTPUT IS:\
  0.488715\
  0.707844\
  0.622769\
  0.394161\
  0.361327
  
<br>

## Multi Layer

Defined by function:\
    A2 = f2(W2(f1(W1P1 + B1)) + B2)

Output of lower layer, is passed to higher layer.

#### Example:
  
##### Multi layer example by passing layer 1 output to layer 2

Layer 1 output is a 5x1 matrix, therefore layer 2 has to have 5 inputs and an arbitrary numbers of neurons.\
Layer 2 requires input as 1x5 matrix, therefore layer 1 output matrix is transposed.\
Layer 2 output is a 3x1 matrix, where each row represents an output of a single neuron.
  
    std::function<double(double)> sigmoid = [](auto x) { return 1 / (1 + exp(-x)); };

    Layer layerOne(5, 2, sigmoid);
    Eigen::MatrixXd inputMatrix = Eigen::MatrixXd::Random(1, 2);
    Eigen::MatrixXd layerOneOutput = layerOne.processInput(inputMatrix);

    std::cout << "LAYER 1 OUTPUT:\n" << layerOneOutput << std::endl;

    Layer layerTwo(3, 5, sigmoid);
    Eigen::MatrixXd layerTwoOutput = layerTwo.processInput(layerOneOutput.transpose());

    std::cout << "LAYER 2 OUTPUT:\n" << layerTwoOutput << std::endl;

> LAYER 1 OUTPUT:\
  0.488715\
  0.707844\
  0.622769\
  0.394161\
  0.361327\
  LAYER 2 OUTPUT:\
  0.972445\
  0.919742\
  0.761817

<br>
