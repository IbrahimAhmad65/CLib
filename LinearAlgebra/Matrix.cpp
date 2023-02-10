//
// Created by ibrahim on 2/5/23.
//

#include <iostream>
#include <valarray>
#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->data = new double[rows * cols];
}

Matrix::Matrix() {
    this->rows = 0;
    this->cols = 0;
    this->data = new double[0];
}

Matrix::Matrix(int rows, int cols, double *data) {
    this->rows = rows;
    this->cols = cols;
    this->data = data;
}

Matrix::Matrix(const Matrix &other) {
    this->rows = other.rows;
    this->cols = other.cols;
    this->data = new double[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        this->data[i] = other.data[i];
    }
}

Matrix::~Matrix() {
    delete[] data;
}

void Matrix::add(const Matrix &other) {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->data[i * this->cols + j] += other.data[i * this->cols + j];
        }
    }
}

void Matrix::subtract(const Matrix &other) {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->data[i * this->cols + j] -= other.data[i * this->cols + j];
        }
    }

}

Matrix Matrix::multiply(const Matrix &other) {
    // Matrix multiplication
    // A = [a11 a12 a13]
    //     [a21 a22 a23]
    //     [a31 a32 a33]
    // B = [b11 b12 b13]
    //     [b21 b22 b23]
    //     [b31 b32 b33]
    // A * B = [a11 * b11 + a12 * b21 + a13 * b31, a11 * b12 + a12 * b22 + a13 * b32, a11 * b13 + a12 * b23 + a13 * b33]
    //         [a21 * b11 + a22 * b21 + a23 * b31, a21 * b12 + a22 * b22 + a23 * b32, a21 * b13 + a22 * b23 + a23 * b33]
    //         [a31 * b11 + a32 * b21 + a33 * b31, a31 * b12 + a32 * b22 + a33 * b32, a31 * b13 + a32 * b23 + a33 * b33]


    Matrix result(this->rows, other.cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            double sum = 0;
            for (int k = 0; k < this->cols; k++) {
                sum += this->data[i * this->cols + k] * other.data[k * other.cols + j];
            }
            result.data[i * other.cols + j] = sum;
        }
    }
    return result;
}

void Matrix::multiply(double scalar) {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->data[i * this->cols + j] *= scalar;
        }
    }
}

void Matrix::divide(double scalar) {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->data[i * this->cols + j] /= scalar;
        }
    }
}

Matrix Matrix::transpose() const {
    Matrix result(this->cols, this->rows);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            result.data[j * this->rows + i] = this->data[i * this->cols + j];
        }
    }
    return result;
}

void Matrix::print() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            std::cout << this->data[i * this->cols + j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::set(int row, int col, double value) {
    data[row * cols + col] = value;
}

double Matrix::get(int row, int col) const {
    return data[row * cols + col];
}

int Matrix::getRows() {
    return rows;
}

int Matrix::getCols() {
    return cols;
}

double *Matrix::getData() const {
    return data;
}

void Matrix::setData(double *data) {
    this->data = data;
}

void Matrix::operator=(const Matrix &other) {
    this->rows = other.rows;
    this->cols = other.cols;
    this->data = new double[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        this->data[i] = other.data[i];
    }
}

void Matrix::operator+=(const Matrix &other) {
    add(other);
}

void Matrix::operator-=(const Matrix &other) {
    subtract(other);
}


void Matrix::operator*=(double scalar) {
    multiply(scalar);
}

void Matrix::operator/=(double scalar) {
    divide(scalar);
}

Matrix Matrix::operator+(const Matrix &other) {
    Matrix selfClone = clone();
    selfClone.add(other);
    return selfClone;
}

Matrix Matrix::operator-(const Matrix &other) {
    Matrix selfClone = clone();
    selfClone.subtract(other);
    return selfClone;
}

Matrix Matrix::operator*(const Matrix &other) {
    Matrix selfClone = clone();
    selfClone.multiply(other);
    return selfClone;
}

Matrix Matrix::operator*(double scalar) {
    Matrix selfClone = clone();
    selfClone.multiply(scalar);
    return selfClone;
}

Matrix Matrix::operator/(double scalar) {
    Matrix selfClone = clone();
    selfClone.divide(scalar);
    return selfClone;
}

bool Matrix::operator==(const Matrix &other) {
    for(int i = 0; i < this->rows; i++) {
        for(int j = 0; j < this->cols; j++) {
            if(this->get(i, j) != other.get(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &other) {
    return !(*this == other);
}


double Matrix::operator()(int row, int col) const {
    return get(row, col);
}


Matrix Matrix::clone() const {
    Matrix clone = Matrix(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            clone.set(i, j, this->get(i, j));
        }
    }
    return clone;
}

Matrix Matrix::operator*(const Vector &other) {
    Matrix them = vectorToMatrix(other);
    Matrix result = *this * them;
    return result;
}

Matrix Matrix::invert() const {
    // invert matrix using Gauss-Jordan elimination
    // https://www.geeksforgeeks.org/program-for-matrix-inverse/
    Matrix result = Matrix(this->rows, this->cols);
    Matrix temp = Matrix(this->rows, this->cols * 2);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            temp.set(i, j, this->get(i, j));
        }
    }
    for (int i = 0; i < this->rows; i++) {
        for (int j = this->cols; j < this->cols * 2; j++) {
            if (i == j - this->cols) {
                temp.set(i, j, 1);
            } else {
                temp.set(i, j, 0);
            }
        }
    }
    temp.rrEchelon();
    for (int i = 0; i < this->rows; i++) {
        for (int j = this->cols; j < this->cols * 2; j++) {
            result.set(i, j - this->cols, temp.get(i, j));
        }
    }
    return result;
}


double Matrix::determinant() const {
    // determinant of matrix
    // https://www.geeksforgeeks.org/determinant-of-a-matrix/

    if (this->rows == 1) {
        return this->get(0, 0);
    }
    double result = 0;
    for (int i = 0; i < this->cols; i++) {
        Matrix minor = this->minor(0, i);
        double cofactor = this->get(0, i) * minor.determinant() * pow(-1, i);
        result += cofactor;
    }
    return result;
}

Matrix Matrix::minor(double a, double b) const {
    // minor matrix
    // https://www.geeksforgeeks.org/adjoint-inverse-matrix/

    Matrix result(this->rows - 1, this->cols - 1);
    int row = 0;
    for (int i = 0; i < this->rows; i++) {
        if (i == a) {
            continue;
        }
        int col = 0;
        for (int j = 0; j < this->cols; j++) {
            if (j == b) {
                continue;
            }
            result.set(row, col, this->get(i, j));
            col++;
        }
        row++;
    }
    return result;
}

Matrix Matrix::solve(const Matrix &other) const {
    // solve matrix
    // https://www.geeksforgeeks.org/program-for-matrix-inverse/

    Matrix result = clone();
    result.augment(other);
    result.rrEchelon();
    return result;
}

Matrix Matrix::solve(const Vector &other) const {
    Matrix them = vectorToMatrix(other);
    Matrix result = solve(them);
    return result;
}

void Matrix::augment(const Matrix &other) {
    // augment matrix
    // https://www.geeksforgeeks.org/program-for-matrix-inverse/

    Matrix result = Matrix(this->rows, this->cols + other.cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            result.set(i, j, this->get(i, j));
        }
    }
    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            result.set(i, j + this->cols, other.get(i, j));
        }
    }
}

void Matrix::rrEchelon() {
    // row reduced echelon form
    // https://www.geeksforgeeks.org/program-for-matrix-inverse/

    int lead = 0;
    for (int r = 0; r < this->rows; r++) {
        if (this->cols <= lead) {
            return;
        }
        int i = r;
        while (this->get(i, lead) == 0) {
            i++;
            if (this->rows == i) {
                i = r;
                lead++;
                if (this->cols == lead) {
                    return;
                }
            }
        }
        for (int j = 0; j < this->cols; j++) {
            double temp = this->get(r, j);
            this->set(r, j, this->get(i, j));
            this->set(i, j, temp);
        }
        double div = this->get(r, lead);
        for (int j = 0; j < this->cols; j++) {
            this->set(r, j, this->get(r, j) / div);
        }
        for (int j = 0; j < this->rows; j++) {
            if (j != r) {
                double sub = this->get(j, lead);
                for (int k = 0; k < this->cols; k++) {
                    this->set(j, k, this->get(j, k) - (sub * this->get(r, k)));
                }
            }
        }
        lead++;
    }
}

Matrix Matrix::identity(int size) {
    Matrix result = Matrix(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                result.set(i, j, 1);
            } else {
                result.set(i, j, 0);
            }
        }
    }
    return result;
}

Matrix Matrix::vectorToMatrix(const Vector &vector) {
    Matrix result = Matrix(vector.getSize(), 1);
    for (int i = 0; i < vector.getSize(); i++) {
        result.set(i, 0, vector.get(i));
    }
    return result;
}

Vector Matrix::matrixToVector(const Matrix &matrix) {
    Vector result = Vector(matrix.rows);
    for (int i = 0; i < matrix.rows; i++) {
        result.set(i, matrix.get(i, 0));
    }
    return result;
}
