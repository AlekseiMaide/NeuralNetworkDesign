# Hamming network

The network is called hamming network due to the fact that the output will be pattern with closest [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance) relative to the input.

Network is used in binary pattern matching problems.

#### FeedForward layer.

Weights are initialized to the PATTERNS we are trying to match.\
Bias matrix values are initialized to the count of features in the patterns.\
All values in output vector end up in range of 0 to bias to ensure proper functioning for recurrent layer.
Activation function is linear.

#### Recurrent "Competitive" layer.

Has same amount of neurons as the previous layer.\
Will continue processing the input until the values converge (There will be only one none zero output) or tie breaking stop condition is met.\
Weights matrix has an identity matrix diagonal and the rest of the values have to be lower than - 1 / (pattern count), which results in every feature being gradually reduced.\
Activation function is Positive linear, which eliminates the values that are moving in the wrong direction.


#### Examples:

Attempts to match supplied pattern to the pattern that has closest hamming distance.

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
    whatIsThisPattern << 0, 1, 1, 0;

    Eigen::MatrixXd firstLayerOutput = feedForwardLayer.processInput(whatIsThisPattern);

    CompetitiveLayer competitiveLayer(patternCount);

    competitiveLayer.processInput(firstLayerOutput);
    
> FeedForward layer weigths:\
    1 1 0 1\
    1 1 0 0\
    0 1 0 0\
    1 0 1 0
  
> FeedForward layer bias: 4 4 4 4

> FeedForward layer output: 5 6 4 4

> Recurrent layer weigths:\
    1.25 -0.25 -0.25 -0.25\
    -0.25  1.25 -0.25 -0.25\
    -0.25 -0.25  1.25 -0.25\
    -0.25 -0.25 -0.25  1.25

> Recurrence: 0 Output is:\
    2.75\
    4.25\
    1.25\
    1.25\
  Recurrence: 1 Output is:\
    1.75\
    4\
    0\
    0\
  Recurrence: 2 Output is:\
    1.1875\
    4.5625\
    0\
    0\
  Recurrence: 3 Output is:\
    0.34375\
    5.40625\
    0\
    0\
  Recurrence: 4 Output is:\
    0\
    6.67188\
    0\
    0

Due to error correcting nature of hamming code, it has to contain at least k+1 difference it patterns, otherwise it is unable to decide.

> Recurrence: 3 Output is:\
    2.8125\
    2.8125\
    0\
    0
