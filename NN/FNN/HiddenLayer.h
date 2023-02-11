//
// Created by ibrahim on 2/10/23.
//

#ifndef MATHLIB_HIDDENLAYER_H
#define MATHLIB_HIDDENLAYER_H


#include "../../LinearAlgebra/Matrix.h"

class HiddenLayer {
public:
    HiddenLayer(int size, int prevSize);

    HiddenLayer(int size, int prevSize, Matrix weights, Matrix biases);

    HiddenLayer(int size, int prevSize, Matrix weights);

    HiddenLayer(int size, int prevSize, Matrix weights, Matrix biases, Matrix activations);

    void updateActivations(const HiddenLayer &l);

    void updateActivations(Matrix activations);

    Matrix getActivations();

    Matrix getWeights();

    Matrix getBiases();

    void setWeights(Matrix weights);

    void setBiases(Matrix biases);

    void setActivations(Matrix activations);

private:
    int size;
    int prevSize;
    Matrix activations;
    Matrix weights;
    Matrix biases;
};


#endif //MATHLIB_HIDDENLAYER_H
