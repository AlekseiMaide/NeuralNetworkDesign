#include <cmath>
#include <functional>
#include "ActivationFunction.h"

std::function<double(double)> sigmoid = [](auto x) { return 1 / (1 + exp(-x)); };
