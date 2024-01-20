#pragma once

#include <iostream>
#include <vector>

typedef unsigned int UINT;

class Matrix;
class Vector;
std::ostream &operator<<(std::ostream &out, const Matrix &other);
double scalerProduct(const Vector &vector_first, const Vector &vector_second);

class Matrix {
public:
	Matrix() : data(0), rows(0), cols(0) {}
	Matrix(UINT rows, UINT cols) : rows(rows), cols(cols) {
        data.resize(rows * cols, 0);
    }

	UINT getRows() const;
	UINT getCols() const;
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
    std::vector<double> data;
    UINT rows, cols;
};

class Vector : public Matrix {
public:
	Vector() {}
	Vector(UINT rows) : Matrix(rows, 1) {}
	double& operator()(UINT row) { return ::Matrix::operator()(row, 0); }
	double operator()(UINT row) const { return ::Matrix::operator()(row, 0); }
};
