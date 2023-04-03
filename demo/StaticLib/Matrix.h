#pragma once

#include <iostream>
#include <vector>

typedef unsigned int UINT;

class Matrix
{
private:
	std::vector<float> matrix;
	UINT rows, cols;
public:
	Matrix() : matrix(0), rows(0), cols(0) {}
	Matrix(std::vector<float> matrix, UINT rows, UINT cols) : matrix(matrix), rows(rows), cols(cols) {}
	Matrix(UINT rows, UINT cols);
	UINT GetRows() const;
	UINT GetCols() const;
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
	Matrix& operator=(const Matrix& other);
	bool operator==(const Matrix& other) const;
	void ToString();

};