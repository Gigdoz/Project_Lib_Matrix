
#include "Matrix.h"

#pragma region exceptions

void __throw_if_out_of_range(const Matrix* other, UINT row, UINT col)
{
	if (row >= other->GetRows() || col >= other->GetCols())
	{
		throw out_of_range("Out of range!");
	}
}
void __throw_if_matrices_size_does_not_match(const Matrix* a, const Matrix* b)
{
	if (a->GetRows() != b->GetRows() || a->GetCols() != b->GetCols())
		throw invalid_argument("The size of the matrices does not match!");
}

void __throw_if_matrices_rows_and_columns_does_not_match(const Matrix* a, const Matrix* b)
{
	if (b->GetRows() != a->GetCols())
		throw invalid_argument("The rows and columns of the matrices does not match!");
}

void __throw_if_non_square_matrix(const Matrix* other)
{
	if (other->GetRows() != other->GetCols())
		throw invalid_argument(" The matrix is not square!");
}
#pragma endregion

Matrix::Matrix() {
	this->rows = 1;
	this->cols = 1;
	this->matrix.resize(this->rows);
	for (UINT i = 0; i < this->rows; i++)
	{
		this->matrix[i].resize(this->cols, 0.0);
	}
}

Matrix::Matrix(UINT rows, UINT cols) {
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(this->rows);
	for (UINT i = 0; i < this->rows; i++)
	{
		this->matrix[i].resize(this->cols, 0.0);
	}
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
	__throw_if_out_of_range(this, row, col);
	return this->matrix[row][col];
}

float Matrix::operator()(UINT row, UINT col) const
{
	__throw_if_out_of_range(this, row, col);
	return this->matrix[row][col];
}

Matrix Matrix::operator+(Matrix& other)
{
	__throw_if_matrices_size_does_not_match(this, &other);
	Matrix sum(rows, cols);
	UINT i, j;
	for (i = 0; i < this->rows; i++)
	{
		for (j = 0; j < this->cols; j++)
		{
			sum(i, j) = this->matrix[i][j] + other(i, j);
		}
	}
	return sum;
}

Matrix Matrix::operator-(Matrix& other)
{
	__throw_if_matrices_size_does_not_match(this, &other);
	Matrix diff(rows, cols);
	UINT i, j;
	for (i = 0; i < this->rows; i++)
	{
		for (j = 0; j < this->cols; j++)
		{
			diff(i, j) = this->matrix[i][j] - other(i, j);
		}
	}
	return diff;
}

Matrix Matrix::operator*(Matrix& other)
{
	__throw_if_matrices_rows_and_columns_does_not_match(this, &other);
	Matrix multip(this->rows, other.GetCols());
	UINT i, j, k;
	float temp = 0.0;
	for (i = 0; i < this->rows; i++)
	{
		for (j = 0; j < other.GetCols(); j++)
		{
			temp = 0.0;
			for (k = 0; k < this->cols; k++)
			{
				temp += this->matrix[i][k] * other(k, j);
			}
			multip(i, j) = temp;
		}
	}
	return multip;
}

Matrix Matrix::operator*(float s)
{
	Matrix result(rows, cols);
	for (UINT i = 0; i < rows; i++)
		for (UINT j = 0; j < cols; j++)
			result(i, j) = matrix[i][j] * s;
	return result;
}

Matrix& Matrix::operator=(Matrix& other)
{

	this->cols = other.GetCols();
	this->rows = other.GetRows();
	this->matrix = other.matrix;
	return *this;
}

Matrix& Matrix::operator+=(Matrix& other)
{

	Matrix A(*this);
	return *this = A + other;
}

Matrix& Matrix::operator-=(Matrix& other)
{

	Matrix A(*this);
	return *this = A - other;
}

Matrix& Matrix::operator*=(Matrix& other)
{
	Matrix A(*this);
	return *this = A * other;
}

Matrix& Matrix::operator*=(float s)
{
	Matrix A(*this);
	return *this = A * s;
}

bool Matrix::operator==(const Matrix& otherMatrix)
{
	__throw_if_matrices_size_does_not_match(this, &otherMatrix);
	for (UINT i = 0; i < this->rows; i++)
		for (UINT j = 0; j < this->cols; j++)
		{
			if (this->matrix[i][j] != otherMatrix(i, j)) return false;
		}
	return true;
}

Matrix Matrix::Transposed_matrix()
{
	Matrix Transpose(cols, rows);
	for (UINT i = 0; i < cols; i++)
	{
		for (UINT j = 0; j < rows; j++) {
			Transpose(i, j) = this->matrix[j][i];
		}
	}
	return Transpose;
}

void Matrix::getMatrixMinor(UINT row, UINT col, Matrix& NewMatrix)
{
	UINT offsetRow = 0;
	UINT offsetCol = 0;
	for (UINT i = 0; i < this->rows - 1; i++) {
		if (i == row)
		{
			offsetRow = 1;
		}
		offsetCol = 0;
		for (UINT j = 0; j < this->rows - 1; j++)
		{
			if (j == col)
			{
				offsetCol = 1;
			}
			NewMatrix(i, j) = this->matrix[i + offsetRow][j + offsetCol];
		}
	}
}

const float Matrix::Det()
{
	__throw_if_non_square_matrix(this);
	int det = 0;
	if (rows == 1) return matrix[0][0];
	if (rows == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	else
	{
		Matrix NewMatrix(rows - 1, rows - 1);
		for (UINT j = 0; j < rows; j++)
		{
			this->getMatrixMinor(0, j, NewMatrix);
			det += pow(-1, j) * matrix[0][j] * NewMatrix.Det();
		}
	}
	return det;
}

void Matrix::print() const
{
	cout << "Matrix: " << endl;
	for (UINT i = 0; i < rows; i++) {
		for (UINT j = 0; j < cols; j++) {
			cout << "[" << matrix[i][j] << "] ";
		}
		cout << endl;
	}
}