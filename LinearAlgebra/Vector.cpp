//
// Created by ibrahim on 2/5/23.
//

#include <iostream>
#include "Vector.h"

Vector::Vector() {
    this->size = 0;
    this->data = new double[0];
}

Vector::Vector(int size) {
    this->size = size;
    this->data = new double[size];
}

Vector::Vector(int size, double *data) {
    this->size = size;
    this->data = data;
}

Vector::Vector(const Vector &other) {
    this->size = other.size;
    this->data = new double[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = other.data[i];
    }
}

Vector::~Vector() {
    delete[] data;
}

void Vector::add(const Vector &other) {
    for (int i = 0; i < this->size; i++) {
        this->data[i] += other.data[i];
    }
}

void Vector::subtract(const Vector &other) {
    for (int i = 0; i < this->size; i++) {
        this->data[i] -= other.data[i];
    }
}

double Vector::dot(const Vector &other) const{
    double result = 0;
    for (int i = 0; i < this->size; i++) {
        result += this->data[i] * other.data[i];
    }
    return result;
}

void Vector::multiply(double scalar) {
    for (int i = 0; i < this->size; i++) {
        this->data[i] *= scalar;
    }
}

void Vector::divide(double scalar) {
    for (int i = 0; i < this->size; i++) {
        this->data[i] /= scalar;
    }
}

void Vector::print() const{
    for (int i = 0; i < this->size; i++) {
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}

void Vector::set(int index, double value) {
    this->data[index] = value;
}

double Vector::get(int index) const {
    return this->data[index];
}

int Vector::getSize() const {
    return this->size;
}

void Vector::setData(double *data) {
    this->data = data;
}

void Vector::operator=(const Vector &other) {
    this->size = other.size;
    this->data = new double[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = other.data[i];
    }
}

void Vector::operator+=(const Vector &other) {
    add(other);
}

void Vector::operator-=(const Vector &other) {
    subtract(other);
}

void Vector::operator*=(double scalar) {
    multiply(scalar);
}

void Vector::operator/=(double scalar) {
    divide(scalar);
}

Vector Vector::operator+(const Vector &other) const{
    Vector thisCopy = clone();
    thisCopy.add(other);
    return thisCopy;
}

Vector Vector::operator-(const Vector &other) const{
    Vector thisCopy = clone();
    thisCopy.subtract(other);
    return thisCopy;}

Vector Vector::operator*(double scalar) const{
    Vector thisCopy = clone();
    thisCopy.multiply(scalar);
    return thisCopy;
}

Vector Vector::operator/(double scalar) const{
    Vector thisCopy = clone();
    thisCopy.divide(scalar);
    return thisCopy;
}

double Vector::operator*(const Vector &other) const{
    return dot(other);
}

double Vector::operator[](int index) const {
    return get(index);
}

Vector Vector::clone() const {
    Vector copy = Vector(this->size);
    for (int i = 0; i < this->size; i++) {
        copy.data[i] = this->data[i];
    }
    return copy;
}

Matrix Vector::toMatrix() {
    Matrix matrix = Matrix(this->size, 1);
    for (int i = 0; i < this->size; i++) {
        matrix.set(i, 0, this->data[i]);
    }
    return matrix;
}
