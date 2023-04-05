#pragma once

#include <iostream>
#include <vector>

typedef unsigned int UINT;

class Vector
{
private:
	std::vector<float> vector;
	UINT size;
public:
	Vector() : vector(0), size(1) {}
	Vector(const Vector& other) : vector(other.vector), size(other.size) {}
	Vector(UINT size) : size(size) { vector.resize(this->size, 0); }
	float operator[](UINT num) const { return this->vector[num]; }
	float& operator[](UINT num) { return this->vector[num];}
	void dataSize(UINT size) { this->size = size; }
};

class Matrix : Vector
{
private:
	Vector data;
	UINT rows, cols;
public:
	Matrix() : Vector(), rows(0), cols(0) {}
	Matrix(const Matrix& other) : data(other.data), rows(other.rows), cols(other.cols) { dataSize(rows * cols); }
	Matrix(UINT rows, UINT cols) : data(rows*cols), rows(rows), cols(cols) {}
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