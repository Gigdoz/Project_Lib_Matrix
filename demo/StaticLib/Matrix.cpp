
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

Matrix::Matrix() 
{
	this->matrix = { 0.0 };
}

Matrix::Matrix(UINT rows, UINT cols)
{
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

bool Matrix::operator==(const Matrix& other) const
{
	if (this->GetRows() != other.GetRows() || this->GetCols() != other.GetCols())
		return false;
	for (UINT i = 0; i < this->rows; i++)
		for (UINT j = 0; j < this->cols; j++)
		{
			if (this->matrix[rows * j + i] != other.matrix[other.rows * j + i]) return false;
		}
	return true;
}

Matrix Matrix::TransposedMatrix()
{
	Matrix Transpose(cols, rows);
	for (UINT i = 0; i < cols; i++)
	{
		for (UINT j = 0; j < rows; j++) {
			Transpose.matrix[Transpose.rows * j + i] = this->matrix[rows * i + j];
		}
	}
	return Transpose;
}

float Matrix::Det() const
{
	__throw_if_non_square_matrix(*this);
	float det = 1.0, q, q0;
	Matrix result(*this);
	if (rows == 1) return matrix[0];
	if (rows == 2) return matrix[0] * matrix[3] - matrix[2] * matrix[1];
	else
	{
		for (UINT k = 0; k < rows; k++)
		{
			q0 = result.matrix[rows * k + k];;
			for (UINT i = k + 1; i < rows; i++)
			{
				q = result.matrix[rows * k + i];
				for (UINT j = k; j < rows; j++)
				{
					result.matrix[rows * j + i] = result.matrix[rows * j + i] - result.matrix[rows * j + k] / q0 * q;
				}
			}
		}
		for (UINT i = 0; i < rows; i++)
			det *= result.matrix[rows * i + i];
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