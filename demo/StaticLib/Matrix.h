#pragma once

#include <iostream>

typedef unsigned int UINT;

class Matrix
{
private:
	float** matrix;
	UINT rows, cols;
	void SetSizeMatrix(UINT rows, UINT cols);
public:

	Matrix() { SetSizeMatrix(1, 1); } // Default Constructor
	Matrix(UINT rows,  UINT cols) { SetSizeMatrix(rows, cols); } // Constructor
	Matrix(const Matrix &other); // Constructor copying
	
	UINT GetRows() const { return rows; }
	UINT GetCols() const { return cols; }
	const float Det();
	void getMatrixMinor(UINT row, UINT col, Matrix &NewMatrix);
	float& operator()(UINT row, UINT col); // The matrix element input
	float operator()(UINT row, UINT col) const; // The matrix element output 
	Matrix Transposed_matrix(); // Transpose of a matrix
	Matrix operator+(const Matrix &otherMatrix);
	Matrix operator-(const Matrix &otherMatrix);
	Matrix operator*(const Matrix &otherMatrix);
	Matrix operator*(float s);
	Matrix& operator+=(const Matrix &otherMatrix);
	Matrix& operator-=(const Matrix &otherMatrix);
	Matrix& operator*=(const Matrix &otherMatrix);
	Matrix& operator*=(float s);
	Matrix& operator=(const Matrix &otherMatrix);
	bool operator==(const Matrix &otherMatrix);
	
	~Matrix(); // destructor
};