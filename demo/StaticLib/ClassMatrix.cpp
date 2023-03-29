
#include "Matrix.h"

using namespace std;

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

void Matrix::SetSizeMatrix(const UINT rows, const UINT cols)
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

void Matrix::InputElementMatrix(const float value, UINT row, UINT col)
{
	if (row < rows && col < cols)
		 matrix[row][col] = value;
	else
	{
		cout << "Out of range!" << endl;
		throw 1;
	}
}

float Matrix::OutputElement(const UINT row, const UINT col)
{
	if (row < rows && col < cols)
		return matrix[row][col];
	else
	{
		cout << "Out of range!" << endl;
		throw 1;
	}
}

Matrix Matrix::operator+(const Matrix &otherMatrix)
{
	if (otherMatrix.matrix)
	{
		if (this->rows == otherMatrix.rows && this->cols == otherMatrix.cols)
		{
			Matrix temp;
			temp.SetSizeMatrix(otherMatrix.rows, otherMatrix.cols);
			for (UINT i = 0; i < temp.rows; i++)
				for (UINT j = 0; j < temp.cols; j++)
				{
					temp.matrix[i][j] = this->matrix[i][j] + otherMatrix.matrix[i][j];

				}
			return temp;
		}
		else
		{
			cout << "The size of the matrices does not match!" << endl;
			throw 1;
		}
	}
	else
	{
		cout << "The matrix don't exist!" << endl;
		throw 1;
	}
}

Matrix Matrix::operator-(const Matrix &otherMatrix)
{
	if (otherMatrix.matrix)
	{
		if (this->rows == otherMatrix.rows && this->cols == otherMatrix.cols)
		{
			Matrix temp;
			temp.SetSizeMatrix(otherMatrix.rows, otherMatrix.cols);
			for (UINT i = 0; i < temp.rows; i++)
				for (UINT j = 0; j < temp.cols; j++)
				{
					temp.matrix[i][j] = this->matrix[i][j] - otherMatrix.matrix[i][j];

				}
			return temp;
		}
		else
		{
			cout << "The size of the matrices does not match!" << endl;
			throw 1;
		}
	}
	else
	{
		cout << "The matrix don't exist!" << endl;
		throw 1;
	}
	
}

Matrix Matrix::operator*(const Matrix &otherMatrix)
{
	if (otherMatrix.matrix)
	{
		
		if (this->cols == otherMatrix.rows)
		{
			Matrix temp;
			UINT k, j, i;
			temp.SetSizeMatrix(rows, otherMatrix.cols);
			for (k = 0; k < temp.rows; k++)
				for (j = 0; j < temp.cols; j++)
				{
					temp.matrix[k][j] = 0;
					for (i = 0; i < cols; i++)
						temp.matrix[k][j] += this->matrix[k][i] * otherMatrix.matrix[i][j];
				}
			return temp;
		}
		else
		{
			cout << "The size of the matrices does not match!" << endl;
			throw 1;
		}
	}
	else
	{
		cout << "The matrix don't exist!" << endl;
		throw 1;
	}
}

Matrix Matrix::operator*(float s)
{
	if (this->matrix)
	{
		Matrix temp;
		temp.SetSizeMatrix(rows, cols);
		for (UINT i = 0; i < temp.rows; i++)
			for (UINT j = 0; j < temp.cols; j++)
			{
				temp.matrix[i][j] = s * this->matrix[i][j];
			}
		return temp;
	}
	else
	{
		cout << "The matrix don't exist!" << endl;
		throw 1;
	}
}

Matrix& Matrix::operator=(const Matrix &otherMatrix)
{
	if (otherMatrix.matrix)
	{
		this->SetSizeMatrix(otherMatrix.rows, otherMatrix.cols);
		for (UINT i = 0; i < this->rows; i++)
			for (UINT j = 0; j < this->cols; j++)
			{
				this->matrix[i][j] = otherMatrix.matrix[i][j];
			}
		return *this;
	}
	else
	{
		cout << "It don't exist!" << endl;
		throw 1;
	}
}

Matrix& Matrix::operator+=(const Matrix &otherMatrix)
{
	if (otherMatrix.matrix)
	{
		if (this->rows == otherMatrix.rows && this->cols == otherMatrix.cols)
		{
			for (UINT i = 0; i < this->rows; i++)
				for (UINT j = 0; j < this->cols; j++)
				{
					this->matrix[i][j] = this->matrix[i][j] + otherMatrix.matrix[i][j];

				}
			return *this;
		}
		else
		{
			cout << "The size of the matrices does not match!" << endl;
			throw 1;
		}
	}
	else
	{
		cout << "The matrix don't exist!" << endl;
		throw 1;
	}
}

bool Matrix::operator==(const Matrix &otherMatrix)
{
	if (otherMatrix.matrix)
	{
		if (this->rows == otherMatrix.rows && this->cols == otherMatrix.cols)
		{

			for (UINT i = 0; i < this->rows; i++)
				for (UINT j = 0; j < this->cols; j++)
				{
					if(this->matrix[i][j] != otherMatrix.matrix[i][j]) return false;
				}
			return true;
		}
		else
		{
			cout << "The size of the matrices does not match!" << endl;
			return false;
		}
	}
	else
	{
		cout << "The matrix don't exist!" << endl;
		throw 1;
	}
}

Matrix Matrix::Transposition_Matrix()
{
	
	if (matrix)
	{
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
	else
	{
		cout << "The matrix don't exist!" << endl;
		throw 1;
	}
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
	if (other.rows == other.cols)
	{
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
	else
	{
		cout << " The matrix is not square!";
		throw 1;
	}
}