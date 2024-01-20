#pragma once

#include <iostream>
#include <vector>

typedef unsigned int UINT;

class Matrix {
public:
	Matrix() : data_(0), rows_(0), cols_(0) {}
	Matrix(UINT rows, UINT cols) : rows_(rows), cols_(cols) {
        data_.resize(rows * cols, 0);
    }
    Matrix(UINT rows, UINT cols, std::initializer_list<double> data);
	UINT rows() const { return rows_; }
	UINT cols() const { return cols_; }
    UINT size() const { return cols_ * rows_;}
	Matrix transpose();
    Matrix& operator=(std::initializer_list<double> data);
	double& operator()(UINT row, UINT col); // The matrix element input
	double operator()(UINT row, UINT col) const; // The matrix element output
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);
	Matrix operator*(double);
    Matrix operator/(double);
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(double);
    Matrix& operator/=(double);
	bool operator==(const Matrix& other) const;

private:
    std::vector<double> data_;
    UINT rows_, cols_;
};

class Vector : public Matrix {
public:
	Vector() = default;
	explicit Vector(UINT rows) : Matrix(rows, 1) {}
    Vector(UINT rows, std::initializer_list<double> data) : Matrix(rows, 1, data) {}
	double& operator()(UINT row) { return ::Matrix::operator()(row, 0); }
	double operator()(UINT row) const { return ::Matrix::operator()(row, 0); }
    double dot(const Vector &other) { return (this->transpose() * other)(0, 0); }
    Vector cross(const Vector& other);
    double norm() const;
};

std::ostream &operator<<(std::ostream &out, const Matrix &other);
