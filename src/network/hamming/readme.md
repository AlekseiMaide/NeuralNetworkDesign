# Hamming network

The network is called hamming network due to the fact that the output will be pattern with closest [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance) relative to the input.

Network is used in binary pattern matching problems.

#### FeedForward layer.

Weights are initialized to the PATTERNS we are trying to match.\
Bias matrix values are initialized to the count of features in the patterns.\
All values in output vector end up in range of 0 to bias to ensure proper functioning for recurrent layer.
Activation function is linear.

#### Recurrent "Competitive" layer.

Has same amount of neurons as the previous layer.

Will continue processing the input until the values converge.

Activation function is Positive linear.


