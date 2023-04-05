
#include "Matrix.h"

using namespace std;

namespace {
	void throwIfOutOfRange(const Matrix& other, UINT row, UINT col)
	{
		if (row >= other.getRows() || col >= other.getCols())
		{
			throw out_of_range("Out of range!");
		}
	}

	void throwIfMatricesSizeDoesNotMatch(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			throw invalid_argument("The size of the matrices does not match!");
		}
	}

	void throwIfMatricesRowsAndColumnsDoesNotMatch(const Matrix& a, const Matrix& b)
	{
		if (b.getRows() != a.getCols())
		{
			throw invalid_argument("The rows and columns of the matrices does not match!");
		}
	}

	void throwIfNonSquareMatrix(const Matrix& other)
	{
		if (other.getRows() != other.getCols())
		{
			throw invalid_argument(" The matrix is not square!");
		}
	}
}

Matrix::Matrix(const vector<float>& data, UINT rows, UINT cols) : data(data), rows(rows), cols(cols)
{
	if (this->data.max_size() == rows * cols)
	{
		throw invalid_argument("The size of the matrices does not match!");
	}
}

UINT Matrix::getRows() const
{
	return this->rows;
}

UINT Matrix::getCols() const
{
	return this->cols;
}

float& Matrix::operator()(UINT row, UINT col)
{
	throwIfOutOfRange(*this, row, col);
	return this->data[rows * col + row];
}

float Matrix::operator()(UINT row, UINT col) const
{
	throwIfOutOfRange(*this, row, col);
	return this->data[rows * col + row];
}

Matrix Matrix::operator+(const Matrix& other)
{
	Matrix result(*this);
	return result += other;
}

Matrix Matrix::operator-(const Matrix& other)
{
	Matrix result(*this);
	return result -= other;
}

Matrix Matrix::operator*(const Matrix& other)
{
	throwIfMatricesRowsAndColumnsDoesNotMatch(*this, other);
	Matrix result(this->rows, other.getCols());
	for (UINT i = 0; i < this->rows; i++)
	{
		for (UINT j = 0; j < other.getCols(); j++)
		{
			for (UINT k = 0; k < this->cols; k++)
			{
				result(i, j) += (*this)(i, k) * other(k, j);
			}
		}
	}
	return result;
}

Matrix Matrix::operator*(float s)
{
	Matrix result(*this);
	return result *= s;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	throwIfMatricesSizeDoesNotMatch(*this, other);
	for (UINT row = 0; row < this->rows; row++)
	{
		for (UINT col = 0; col < this->cols; col++)
		{
			(*this)(row, col) += other(row, col);
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	throwIfMatricesSizeDoesNotMatch(*this, other);
	for (UINT row = 0; row < this->rows; row++)
	{
		for (UINT col = 0; col < this->cols; col++)
		{
			(*this)(row, col) -= other(row, col);
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
	{
		for (UINT j = 0; j < cols; j++)
		{
			(*this)(i, j) *= s;
		}
	}
	return *this;
}

bool Matrix::operator==(const Matrix& other) const
{
	if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
	{
		return false;
	}
	for (UINT i = 0; i < this->rows; i++)
	{
		for (UINT j = 0; j < this->cols; j++)
		{
			if (this->data[rows * j + i] != other.data[other.rows * j + i])
			{
				return false;
			}
		}
	}
	return true;
}

Matrix Matrix::transposedMatrix()
{
	Matrix Transpose(cols, rows);
	for (UINT i = 0; i < cols; i++)
	{
		for (UINT j = 0; j < rows; j++) 
		{
			Transpose(i, j) = (*this)(j, i);
		}
	}
	return Transpose;
}

void Matrix::toString()
{
	cout << "Matrix: " << endl;
	for (UINT row = 0; row < rows; row++)
	{
		for (UINT col = 0; col < cols; col++)
		{
			cout << "[" << (*this)(row, col) << "] ";
		}
		cout << endl;
	}
}