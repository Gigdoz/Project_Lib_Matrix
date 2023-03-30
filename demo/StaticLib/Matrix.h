#pragma once

#include <iostream>
#include <vector>

typedef unsigned int UINT;
using namespace std;

class Matrix
{
private:
	vector<vector<float> > matrix;
	UINT rows, cols;
public:
	Matrix(); // Default Constructor
	Matrix(UINT, UINT); // Constructor
	Matrix(const Matrix&); // Constructor copying
	UINT GetRows() const;
	UINT GetCols() const;
	const float Det();
	void getMatrixMinor(UINT, UINT, Matrix&);
	float& operator()(UINT, UINT); // The matrix element input
	float operator()(UINT, UINT) const; // The matrix element output 
	Matrix Transposed_matrix(); // Transpose of a matrix
	// Matrix Operations
	Matrix operator+(Matrix&);
	Matrix operator-(Matrix&);
	Matrix operator*(Matrix&);
	Matrix operator*(float);
	Matrix& operator+=(Matrix&);
	Matrix& operator-=(Matrix&);
	Matrix& operator*=(Matrix&);
	Matrix& operator*=(float);
	Matrix& operator=(Matrix&);
	bool operator==(const Matrix&);
	void print() const;

};