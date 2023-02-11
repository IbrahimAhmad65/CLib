//
// Created by ibrahim on 2/10/23.
//

#include "HiddenLayer.h"

HiddenLayer::HiddenLayer(int size, int prevSize) {
    this-> size = size;
    this-> prevSize = prevSize;
    this->weights = Matrix(size,prevSize);
    this->biases = Matrix(size,1);
    this->activations = Matrix(size,1);
}

HiddenLayer::HiddenLayer(int size, int prevSize, Matrix weights, Matrix biases) {
    this-> size = size;
    this-> prevSize = prevSize;
    this->weights = weights;
    this->biases = biases;
    this->activations = Matrix(size,1);
}

HiddenLayer::HiddenLayer(int size, int prevSize, Matrix weights) {
    this-> size = size;
    this-> prevSize = prevSize;
    this->weights = weights;
    this->biases = Matrix(size,1);
    this->activations = Matrix(size,1);
}

HiddenLayer::HiddenLayer(int size, int prevSize, Matrix weights, Matrix biases, Matrix activations) {
    this-> size = size;
    this-> prevSize = prevSize;
    this->weights = weights;
    this->biases = biases;
    this->activations = activations;
}

void HiddenLayer::updateActivations(const HiddenLayer &l) {
    activations = weights * l.activations + biases;
}

Matrix HiddenLayer::getWeights() {
    return weights;
}

Matrix HiddenLayer::getBiases() {
    return biases;
}

void HiddenLayer::setWeights(Matrix weights) {
    this-> weights = weights;
}

void HiddenLayer::setBiases(Matrix biases) {
    this-> biases = biases;
}

void HiddenLayer::setActivations(Matrix activations) {
    this-> activations = activations;
}

void HiddenLayer::updateActivations(Matrix activations) {
    this->activations = weights*activations + biases;
}

Matrix HiddenLayer::getActivations() {
    return activations;
}
