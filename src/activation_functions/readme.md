## Activation functions:

#### Sigmoid

    Special case of logistic function where limits are between 0 and 1
    Nonlinearity of this function creates "ease-in" or "ease-out" effect due to which the rate of change is slower at the extremes and faster in the centre.
    Put plainly, we want the neuron to “make its mind up” instead of indecisively staying in the middle.

#### Hard limit

    Forces a neuron to output a 1 if its net input reaches a threshold, otherwise it outputs 0.
    This allows a neuron to make a decision or classification. It can say yes or no. 
    This kind of neuron is often trained with the perceptron learning rule.
    
#### Positive linear

    0 <= n <= 1     -> n
    n >= 0          -> 0
    n <= 1          -> 1
