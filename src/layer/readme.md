## Notation:

    (a)     Lowercase letter - Scalar value
    (A)     Uppercase letter - Matrix or Vector

<br>

## Layer

Described by function:
    A = f(WP + B)
    
    WP + B = W(1,1) * P(1,1) + B(1,1) + W(1,2) * P(1,2) + B(1,2) +  ...  + W(1,n) * P(1,n) + B(1,n)
    W = Matrix of weights
    P = Matrix of inputs
    B = Matrix of neuron biases
    f = activation/transfer function.
    A = Output Matrix
    
#### Example:
    
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
