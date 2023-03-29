
#include "Matrix.h"

using namespace std;

#pragma region exceptions

void __throw_if_out_of_range(Matrix* m, UINT row, UINT col)
{
	if (row >= m->GetRows() || col >= m->GetCols())
	{
		throw std::out_of_range("Out of range!");
	}
}
void __throw_if_matrices_size_does_not_match(const Matrix* a, const Matrix* b)
{
	if (a->GetRows() != b->GetRows() || a->GetCols() != b->GetCols())
		throw std::invalid_argument("The size of the matrices does not match!");
}

void __throw_if_matrices_rows_and_columns_does_not_match(const Matrix* a, const Matrix* b)
{
	if (b->GetRows() != a->GetCols())
		throw std::invalid_argument("The rows and columns of the matrices does not match!");
}

void __throw_if_matrix_does_not_exist(float** matrix_array)
{
	if (!matrix_array)
		throw std::invalid_argument("The matrix don't exist!");
}
void __throw_if_non_square_matrix(Matrix* m)
{
	if (m->GetRows() != m->GetCols())
		throw std::invalid_argument(" The matrix is not square!");
}
#pragma endregion

Matrix::Matrix(const Matrix &otherMatrix) // Constructor copying
{
	this->SetSizeMatrix(otherMatrix.rows, otherMatrix.cols);
	for (UINT i = 0; i < otherMatrix.rows; i++)
		for (UINT j = 0; j < otherMatrix.cols; j++)
			this->matrix[i][j] = otherMatrix.matrix[i][j];
}

Matrix::~Matrix()
{
	for (UINT i = 0; i < this->rows; i++)
		delete[] this->matrix[i];
	delete[] this->matrix;
}

void Matrix::SetSizeMatrix(UINT rows, UINT cols)
{
	this->rows = rows;
	this->cols = cols;
	this->matrix = new float* [rows];
	for (UINT i = 0; i < rows; i++)
		this->matrix[i] = new float[cols];
	for (UINT i = 0; i < this->rows; i++)
		for (UINT j = 0; j < this->cols; j++)
			this->matrix[i][j] = NULL;
}

void Matrix::InputElementMatrix(float value, UINT row, UINT col)
{
	__throw_if_out_of_range(this, row, col);
	matrix[row][col] = value;
}

float Matrix::OutputElement(UINT row, UINT col)
{
	__throw_if_out_of_range(this, row, col);
	return matrix[row][col];
}

Matrix Matrix::operator+(const Matrix &otherMatrix)
{
	__throw_if_matrix_does_not_exist(otherMatrix.matrix);
	__throw_if_matrices_size_does_not_match(this, &otherMatrix);
	Matrix temp;
	temp.SetSizeMatrix(otherMatrix.rows, otherMatrix.cols);
	for (UINT i = 0; i < temp.rows; i++)
		for (UINT j = 0; j < temp.cols; j++)
		{
			temp.matrix[i][j] = this->matrix[i][j] + otherMatrix.matrix[i][j];

		}
	return temp;
}

Matrix Matrix::operator-(const Matrix &otherMatrix)
{
	__throw_if_matrix_does_not_exist(otherMatrix.matrix);
	__throw_if_matrices_size_does_not_match(this, &otherMatrix);
	Matrix temp;
	temp.SetSizeMatrix(otherMatrix.rows, otherMatrix.cols);
	for (UINT i = 0; i < temp.rows; i++)
		for (UINT j = 0; j < temp.cols; j++)
		{
			temp.matrix[i][j] = this->matrix[i][j] - otherMatrix.matrix[i][j];

		}
	return temp;
}

Matrix Matrix::operator*(const Matrix &otherMatrix)
{
	__throw_if_matrix_does_not_exist(otherMatrix.matrix);
	__throw_if_matrices_rows_and_columns_does_not_match(this, &otherMatrix);
	Matrix temp;
	temp.SetSizeMatrix(rows, otherMatrix.cols);
	for (UINT k = 0; k < temp.rows; k++)
		for (UINT j = 0; j < temp.cols; j++)
		{
			temp.matrix[k][j] = 0;
			for (UINT i = 0; i < cols; i++)
				temp.matrix[k][j] += this->matrix[k][i] * otherMatrix.matrix[i][j];
		}
	return temp;
}

Matrix Matrix::operator*(float s)
{
	__throw_if_matrix_does_not_exist(this->matrix);
	Matrix temp;
	temp.SetSizeMatrix(rows, cols);
	for (UINT i = 0; i < temp.rows; i++)
		for (UINT j = 0; j < temp.cols; j++)
		{
			temp.matrix[i][j] = s * this->matrix[i][j];
		}
	return temp;
}

Matrix& Matrix::operator=(const Matrix &otherMatrix)
{
	__throw_if_matrix_does_not_exist(otherMatrix.matrix);
	this->SetSizeMatrix(otherMatrix.rows, otherMatrix.cols);
	for (UINT i = 0; i < this->rows; i++)
		for (UINT j = 0; j < this->cols; j++)
		{
			this->matrix[i][j] = otherMatrix.matrix[i][j];
		}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix &otherMatrix)
{
	__throw_if_matrix_does_not_exist(otherMatrix.matrix);
	__throw_if_matrices_size_does_not_match(this, &otherMatrix);
	for (UINT i = 0; i < this->rows; i++)
		for (UINT j = 0; j < this->cols; j++)
		{
			this->matrix[i][j] = this->matrix[i][j] + otherMatrix.matrix[i][j];
		}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix &otherMatrix)
{
	__throw_if_matrix_does_not_exist(otherMatrix.matrix);
	__throw_if_matrices_size_does_not_match(this, &otherMatrix);
	for (UINT i = 0; i < this->rows; i++)
		for (UINT j = 0; j < this->cols; j++)
		{
			this->matrix[i][j] = this->matrix[i][j] - otherMatrix.matrix[i][j];
		}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix &otherMatrix)
{
	__throw_if_matrix_does_not_exist(otherMatrix.matrix);
	__throw_if_matrices_rows_and_columns_does_not_match(this, &otherMatrix);
	Matrix temp;
	temp.SetSizeMatrix(this->rows, otherMatrix.cols);
	for (UINT k = 0; k < temp.rows; k++)
		for (UINT j = 0; j < temp.cols; j++)
		{
			temp.matrix[k][j] = 0;
			for (UINT i = 0; i < this->cols; i++)
				temp.matrix[k][j] += this->matrix[k][i] * otherMatrix.matrix[i][j];
		}
	this->SetSizeMatrix(temp.rows, temp.cols);
	*this = temp;
	return *this;
}

Matrix& Matrix::operator*=(float s)
{
	__throw_if_matrix_does_not_exist(this->matrix);
	for (UINT i = 0; i < this->rows; i++)
		for (UINT j = 0; j < this->cols; j++)
		{
			this->matrix[i][j] = s * this->matrix[i][j];
		}
	return *this;
}

bool Matrix::operator==(const Matrix &otherMatrix)
{
	__throw_if_matrix_does_not_exist(otherMatrix.matrix);
	__throw_if_matrices_size_does_not_match(this, &otherMatrix);
	for (UINT i = 0; i < this->rows; i++)
		for (UINT j = 0; j < this->cols; j++)
		{
			if(this->matrix[i][j] != otherMatrix.matrix[i][j]) return false;
		}
	return true;
}

Matrix Matrix::Transposition_Matrix()
{
	
	__throw_if_matrix_does_not_exist(this->matrix);
	Matrix NewMatrix(cols, rows);
	for (UINT i = 0; i < rows; i++)
		for (UINT j = 0; j < cols; j++)
		{
			NewMatrix.matrix[j][i] = matrix[i][j];
		}
	Matrix temp(cols, rows);
	for (UINT i = 0; i < rows; i++)
		for (UINT j = 0; j < cols; j++)
		{
			 temp.matrix[j][i] =  matrix[i][j];
		}
	for (UINT i = 0; i < cols; i++)
		for (UINT j = 0; j < rows; j++)
		{
			NewMatrix.matrix[i][j] = temp.matrix[i][j];
		}
	return NewMatrix;
}

void getMatrixMinor(Matrix &other, UINT row, UINT col, Matrix &NewMatrix)
{
	UINT offsetRow = 0;
	UINT offsetCol = 0;
	for (UINT i = 0; i < other.rows - 1; i++) {

		if (i == row)
		{
			offsetRow = 1;
		}

		offsetCol = 0;
		for (UINT j = 0; j < other.rows - 1; j++)
		{
			if (j == col)
			{
				offsetCol = 1;
			}
			NewMatrix.matrix[i][j] = other.matrix[i + offsetRow][j + offsetCol];
		}
	}
}

float Det(Matrix &other) {
	__throw_if_non_square_matrix(&other);
	int det = 0;
	if (other.rows == 1) return other.matrix[0][0];
	if (other.rows == 2) return other.matrix[0][0] * other.matrix[1][1] - other.matrix[0][1] * other.matrix[1][0];
	else
	{
		Matrix NewMatrix;
		NewMatrix.SetSizeMatrix(other.rows - 1, other.rows - 1);
		for (UINT j = 0; j < other.rows; j++)
		{
			getMatrixMinor(other, 0, j, NewMatrix);
			det += pow(-1, j) * other.matrix[0][j] * Det(NewMatrix);
		}
	}
	return det;
}