#pragma once

#include <iostream>
#include <vector>

typedef unsigned int UINT;

class Matrix
{
private:
	std::vector<float> data;
	UINT rows, cols;
public:
	Matrix() : data(0), rows(0), cols(0) {}
	Matrix(const Matrix& other) : data(other.data), rows(other.rows), cols(other.cols) {}
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
	Vector() : Matrix() {}
	Vector(UINT rows) : Matrix(rows, 1) {}
	Vector(const Matrix& other) : Matrix(other) {}
	float& operator()(UINT row) { return ::Matrix::operator()(row, 0); } // The matrix element input
	float operator()(UINT row) const { return ::Matrix::operator()(row, 0); }; // The matrix element output 
};