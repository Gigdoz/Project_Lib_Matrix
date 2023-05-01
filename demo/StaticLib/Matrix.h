#pragma once

#include <iostream>
#include <vector>

typedef unsigned int UINT;

class Matrix;
std::ostream &operator<< (std::ostream &out, const Matrix &other);

class Matrix
{
private:
	std::vector<float> data;
	UINT rows, cols;
public:
	Matrix() : data(0), rows(0), cols(0) {}
	Matrix(UINT rows, UINT cols) : rows(rows), cols(cols) { data.resize(rows * cols, 0); }
	UINT getRows() const;
	UINT getCols() const;
	Matrix transposedMatrix();
	float& operator()(UINT row, UINT col); // The matrix element input
	float operator()(UINT row, UINT col) const; // The matrix element output 
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);
	Matrix operator*(float);
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(float);
	bool operator==(const Matrix& other) const;
	void toString();
};

class Vector : public Matrix
{
public:
	Vector() {}
	Vector(UINT rows) : Matrix(rows, 1) {}
	float& operator()(UINT row) { return ::Matrix::operator()(row, 0); }
	float operator()(UINT row) const { return ::Matrix::operator()(row, 0); }
};