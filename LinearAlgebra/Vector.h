//
// Created by ibrahim on 2/5/23.
//

#ifndef MATHLIB_VECTOR_H
#define MATHLIB_VECTOR_H



class Vector {
public:
    Vector();

    explicit Vector(int size);

    Vector(int size, double *data);

    Vector(const Vector &other);

    ~Vector();

    void add(const Vector &other);

    void subtract(const Vector &other);

    double dot(const Vector &other) const;

    void multiply(double scalar);

    void divide(double scalar);

    void print() const;

    void set(int index, double value);

    [[nodiscard]] double get(int index) const;

    [[nodiscard]] int getSize() const;

    void setData(double *data);

    void operator=(const Vector &other);

    void operator+=(const Vector &other);

    void operator-=(const Vector &other);

    void operator*=(double scalar);

    void operator/=(double scalar);

    Vector operator+(const Vector &other) const;

    Vector operator-(const Vector &other) const;

    Vector operator*(double scalar) const;

    Vector operator/(double scalar) const;

    double operator*(const Vector &other) const;

    double operator[](int index) const const;

    Vector clone() const;

private:
    int size;
    double *data;
};


#endif //MATHLIB_VECTOR_H
