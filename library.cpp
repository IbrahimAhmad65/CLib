#include "library.h"
#include "LinearAlgebra/Matrix.h"
#include "NN/FNN/HiddenLayer.h"

int main() {
    double firstActivation[] = {1,2,2};
    double biases[] = {0,0,0,0};
    double weights[] = {-1,3,-1,
                        0,0,0,
                        1,5,1,
                        -2,-7,-2,
    };
    Matrix bias = Matrix(4,1, biases);
    Matrix weight = Matrix(4,3, weights);
    Matrix initActivations = Matrix(3,1, firstActivation);
    HiddenLayer h = HiddenLayer(4,3,weight,bias);
    h.updateActivations(initActivations);
    h.getActivations().print();
    return 0;
}
