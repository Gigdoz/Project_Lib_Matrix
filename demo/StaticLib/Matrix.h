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
	Matrix();
	Matrix(UINT row, UINT col);
	Matrix(const Matrix &other);
	UINT GetRows() const;
	UINT GetCols() const;
	float Det() const;
	float& operator()(UINT row, UINT col); // The matrix element input
	float operator()(UINT row, UINT col) const; // The matrix element output 
	Matrix TransposedMatrix();
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);
	Matrix operator*(float);
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(float);
	Matrix& operator=(const Matrix& other);
	bool operator==(const Matrix& other);
	void print();

};