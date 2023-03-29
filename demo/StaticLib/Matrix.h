#pragma once

#include <iostream>

typedef unsigned int UINT;

class Matrix
{

	friend void getMatrixMinor(Matrix &other, UINT row, UINT col, Matrix &NewMatrix);
	friend float Det(Matrix &other);
private:
	float** matrix;
	UINT rows, cols;
public:

	Matrix() { SetSizeMatrix(1, 1); } // Default Constructor
	Matrix(UINT rows,  UINT cols) { SetSizeMatrix(rows, cols); } // Constructor
	Matrix(const Matrix &other); // Constructor copying
	void SetSizeMatrix(UINT rows, UINT cols);
	UINT GetRows() const { return rows; }
	UINT GetCols() const { return cols; }
	void operator()(float value, UINT row, UINT col); // The matrix element input
	float operator()(UINT row, UINT col); // The matrix element output 
	Matrix Transposition_Matrix(); // Transposition matrix
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