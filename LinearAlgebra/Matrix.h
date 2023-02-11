//
// Created by ibrahim on 2/5/23.
//

#ifndef MATHLIB_MATRIX_H
#define MATHLIB_MATRIX_H


#include "Vector.h"

class Matrix {

public:
    Matrix();

    Matrix(int rows, int cols);

    Matrix(int rows, int cols, double *data);

    Matrix(const Matrix &other);

    ~Matrix();

    void add(const Matrix &other);

    void subtract(const Matrix &other);

    Matrix multiply(const Matrix &other);

    Matrix invert() const;


    void multiply(double scalar);

    void divide(double scalar);

    [[nodiscard]] Matrix transpose() const;

    [[nodiscard]] Matrix cofactor() const;

    [[nodiscard]] double determinant() const;

    Matrix solve(const Matrix &other) const;

    Matrix solve(const Vector &other) const;

    void augment(const Matrix &other);

    void rrEchelon();


    void print();

    void set(int row, int col, double value);

    int getRows();

    int getCols();

    void setData(double *data);

    void operator=(const Matrix &other);

    void operator+=(const Matrix &other);

    void operator-=(const Matrix &other);

    void operator*=(double scalar);

    void operator/=(double scalar);

    Matrix operator+(const Matrix &other) const;

    Matrix operator-(const Matrix &other) const;

    Matrix operator*(const Matrix &other) const;

    Matrix operator*(const Vector &other);

    Matrix operator*(double scalar) const;

    Matrix operator/(double scalar);

    bool operator==(const Matrix &other);

    bool operator!=(const Matrix &other);

    double operator()(int row, int col) const;

    [[nodiscard]] double *getData() const;

    [[nodiscard]] Matrix clone() const;

    [[nodiscard]] Matrix minor(double a, double b) const;
    static Matrix identity(int size);
    static Matrix vectorToMatrix(const Vector &vector);
    static Vector matrixToVector(const Matrix &matrix);

private:

    int rows;

    int cols;

    double *data;

    double get(int row, int col) const;
};


#endif //MATHLIB_MATRIX_H
