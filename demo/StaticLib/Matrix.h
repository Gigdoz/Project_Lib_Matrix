#pragma once

#include <iostream>

typedef unsigned int UINT;

class Matrix
{
private:
	float** matrix;
	UINT rows, cols;
	void SetSizeMatrix(UINT, UINT);
public:

	Matrix() { SetSizeMatrix(1, 1); } // Default Constructor
	Matrix(UINT rows,  UINT cols) { SetSizeMatrix(rows, cols); } // Constructor
	Matrix(const Matrix &other); // Constructor copying
	
	UINT GetRows() const { return rows; }
	UINT GetCols() const { return cols; }
	const float Det();
	void getMatrixMinor(UINT, UINT, Matrix &NewMatrix);
	float& operator()(UINT, UINT); // The matrix element input
	float operator()(UINT, UINT) const; // The matrix element output 
	Matrix Transposed_matrix(); // Transpose of a matrix
	Matrix operator+(const Matrix &);
	Matrix operator-(const Matrix &);
	Matrix operator*(const Matrix &);
	Matrix operator*(float s);
	Matrix& operator+=(const Matrix &);
	Matrix& operator-=(const Matrix &);
	Matrix& operator*=(const Matrix &);
	Matrix& operator*=(float s);
	Matrix& operator=(const Matrix &);
	bool operator==(const Matrix &);
	
	~Matrix(); // destructor
};
