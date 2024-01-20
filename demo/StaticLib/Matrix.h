#pragma once

#include <iostream>
#include <vector>

typedef unsigned int UINT;

class Matrix;
class Vector;
std::ostream &operator<<(std::ostream &out, const Matrix &other);

class Matrix {
public:
	Matrix() : data_(0), rows_(0), cols_(0) {}
	Matrix(UINT rows, UINT cols) : rows_(rows), cols_(cols) {
        data_.resize(rows * cols, 0);
    }

	UINT rows() const { return this->rows_; }
	UINT cols() const { return this->cols_; }
	Matrix transpose();
	double& operator()(UINT row, UINT col); // The matrix element input
	double operator()(UINT row, UINT col) const; // The matrix element output
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);
	Matrix operator*(double);
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(double);
	bool operator==(const Matrix& other) const;

private:
    std::vector<double> data_;
    UINT rows_, cols_;
};

class Vector : public Matrix {
public:
	Vector() {}
	Vector(UINT rows) : Matrix(rows, 1) {}
	double& operator()(UINT row) { return ::Matrix::operator()(row, 0); }
	double operator()(UINT row) const { return ::Matrix::operator()(row, 0); }
    double dot(const Vector &other) { return (this->transpose() * other)(0, 0); }
};
