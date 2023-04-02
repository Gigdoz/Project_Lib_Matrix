
#include "Matrix.h"

using namespace std;

namespace {
	void __throw_if_out_of_range(const Matrix& other, UINT row, UINT col)
	{
		if (row >= other.GetRows() || col >= other.GetCols())
		{
			throw out_of_range("Out of range!");
		}
	}
	void __throw_if_matrices_size_does_not_match(const Matrix& a, const Matrix& b)
	{
		if (a.GetRows() != b.GetRows() || a.GetCols() != b.GetCols())
			throw invalid_argument("The size of the matrices does not match!");
	}

	void __throw_if_matrices_rows_and_columns_does_not_match(const Matrix& a, const Matrix& b)
	{
		if (b.GetRows() != a.GetCols())
			throw invalid_argument("The rows and columns of the matrices does not match!");
	}

	void __throw_if_non_square_matrix(const Matrix& other)
	{
		if (other.GetRows() != other.GetCols())
			throw invalid_argument(" The matrix is not square!");
	}
}

Matrix::Matrix() {
	this->rows = 1;
	this->cols = 1;
	this->matrix.resize(rows*cols, 0.0);
}

Matrix::Matrix(UINT rows, UINT cols) {
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(this->rows * this->cols, 0.0);
}

Matrix::Matrix(const Matrix& other)
{
	this->cols = other.GetCols();
	this->rows = other.GetRows();
	this->matrix = other.matrix;

}

UINT Matrix::GetRows() const
{
	return this->rows;
}

UINT Matrix::GetCols() const
{
	return this->cols;
}

float& Matrix::operator()(UINT row, UINT col)
{
	__throw_if_out_of_range(*this, row, col);
	return this->matrix[rows * col + row];
}

float Matrix::operator()(UINT row, UINT col) const
{
	__throw_if_out_of_range(*this, row, col);
	return this->matrix[rows * col + row];
}

Matrix Matrix::operator+(const Matrix& other)
{
	Matrix sum(*this);
	return sum += other;
}

Matrix Matrix::operator-(const Matrix& other)
{
	Matrix diff(*this);
	return diff -= other;
}

Matrix Matrix::operator*(const Matrix& other)
{
	__throw_if_matrices_rows_and_columns_does_not_match(*this, other);
	Matrix multip(this->rows, other.GetCols());
	for (UINT i = 0; i < this->rows; i++)
	{
		for (UINT j = 0; j < other.GetCols(); j++)
		{
			for (UINT k = 0; k < this->cols; k++)
			{
				multip.matrix[multip.rows * j + i] += this->matrix[rows * k + i] * other.matrix[other.rows * j + k];
			}
		}
	}
	return multip;
}

Matrix Matrix::operator*(float s)
{
	Matrix result(*this);
	return result *= s;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	this->cols = other.GetCols();
	this->rows = other.GetRows();
	this->matrix = other.matrix;
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	__throw_if_matrices_size_does_not_match(*this, other);
	for (UINT row = 0; row < this->rows; row++)
	{
		for (UINT col = 0; col < this->cols; col++)
		{
			this->matrix[rows * col + row] = this->matrix[rows * col + row] + other.matrix[other.rows * col + row];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	__throw_if_matrices_size_does_not_match(*this, other);
	for (UINT row = 0; row < this->rows; row++)
	{
		for (UINT col = 0; col < this->cols; col++)
		{
			this->matrix[rows * col + row] = this->matrix[rows * col + row] - other.matrix[other.rows * col + row];
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	return *this = *this * other;
}

Matrix& Matrix::operator*=(float s)
{
	for (UINT i = 0; i < rows; i++)
		for (UINT j = 0; j < cols; j++)
			this->matrix[rows * j + i] = this->matrix[rows * j + i] * s;
	return *this;
}

bool Matrix::operator==(const Matrix& otherMatrix)
{
	__throw_if_matrices_size_does_not_match(*this, otherMatrix);
	for (UINT i = 0; i < this->rows; i++)
		for (UINT j = 0; j < this->cols; j++)
		{
			if (this->matrix[rows * j + i] != otherMatrix.matrix[otherMatrix.rows * j + i]) return false;
		}
	return true;
}

Matrix Matrix::TransposedMatrix()
{
	Matrix Transpose(cols, rows);
	for (UINT i = 0; i < cols; i++)
	{
		for (UINT j = 0; j < rows; j++) {
			Transpose(i, j) = this->matrix[rows * i + j];
		}
	}
	return Transpose;
}

void getMatrixMinor(const Matrix &matrix, UINT row, UINT col, Matrix &NewMatrix)
{
	UINT offsetRow = 0;
	UINT offsetCol = 0;
	for (UINT i = 0; i < matrix.GetRows() - 1; i++) {
		if (i == row)
		{
			offsetRow = 1;
		}
		offsetCol = 0;
		for (UINT j = 0; j < matrix.GetRows() - 1; j++)
		{
			if (j == col)
			{
				offsetCol = 1;
			}
			NewMatrix(i, j) = matrix(i + offsetRow, j + offsetCol);
		}
	}
}

float Matrix::Det() const
{
	__throw_if_non_square_matrix(*this);
	int det = 0;
	if (rows == 1) return matrix[0];
	if (rows == 2) return matrix[0] * matrix[3] - matrix[2] * matrix[1];
	else
	{
		Matrix NewMatrix(rows - 1, rows - 1);
		for (UINT row = 0; row < rows; row++)
		{
			getMatrixMinor(*this, 0, row, NewMatrix);
			det += pow(-1, row) * matrix[rows * row] * NewMatrix.Det();
		}
	}
	return det;
}

void Matrix::print()
{
	cout << "Matrix: " << endl;
	for (UINT row = 0; row < rows; row++) {
		for (UINT col = 0; col < cols; col++)
			cout << "[" << matrix[rows * col + row] << "] ";
		cout << endl;
	}
}