
#include "Matrix.h"

using namespace std;

Matrixs::Matrixs(const Matrixs &otherMatrix) // Constructor copying
{
	this->SetSizeMatrix(otherMatrix.rows, otherMatrix.cols);
	for (UINT i = 0; i < otherMatrix.rows; i++)
		for (UINT j = 0; j < otherMatrix.cols; j++)
			this->matrix[i][j] = otherMatrix.matrix[i][j];
}

Matrixs::~Matrixs()
{
	for (UINT i = 0; i < this->rows; i++)
		delete[] this->matrix[i];
	delete[] this->matrix;
}

void Matrixs::SetSizeMatrix(const UINT rows, const UINT cols)
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

void Matrixs::InputElementMatrix(const float value, UINT row, UINT col)
{
	if (row < rows && col < cols)
		 matrix[row][col] = value;
	else
	{
		cout << "Out of range!" << endl;
		throw 1;
	}
}

float Matrixs::OutputElement(const UINT row, const UINT col)
{
	if (row < rows && col < cols)
		return matrix[row][col];
	else
	{
		cout << "Out of range!" << endl;
		throw 1;
	}
}

Matrixs Matrixs::operator+(const Matrixs &otherMatrix)
{
	if (otherMatrix.matrix)
	{
		if (this->rows == otherMatrix.rows && this->cols == otherMatrix.cols)
		{
			Matrixs temp;
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

Matrixs Matrixs::operator-(const Matrixs &otherMatrix)
{
	if (otherMatrix.matrix)
	{
		if (this->rows == otherMatrix.rows && this->cols == otherMatrix.cols)
		{
			Matrixs temp;
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

Matrixs Matrixs::operator*(const Matrixs &otherMatrix)
{
	if (otherMatrix.matrix)
	{
		
		if (this->cols == otherMatrix.rows)
		{
			Matrixs temp;
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

Matrixs Matrixs::operator*(float s)
{
	if (this->matrix)
	{
		Matrixs temp;
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

Matrixs& Matrixs::operator=(const Matrixs &otherMatrix)
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

Matrixs& Matrixs::operator+=(const Matrixs &otherMatrix)
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

bool Matrixs::operator==(const Matrixs &otherMatrix)
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

Matrixs Matrixs::T()
{
	
	if (matrix)
	{
		Matrixs NewMatrix(cols, rows);
		for (UINT i = 0; i < rows; i++)
			for (UINT j = 0; j < cols; j++)
			{
				NewMatrix.matrix[j][i] = matrix[i][j];
			}
		Matrixs temp(cols, rows);
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

void getMatrixMinor(Matrixs& Matrix, UINT row, UINT col, Matrixs &NewMatrix)
{
	UINT offsetRow = 0;
	UINT offsetCol = 0;
	for (UINT i = 0; i < Matrix.rows - 1; i++) {

		if (i == row)
		{
			offsetRow = 1;
		}

		offsetCol = 0;
		for (UINT j = 0; j < Matrix.rows - 1; j++)
		{
			if (j == col)
			{
				offsetCol = 1;
			}
			NewMatrix.matrix[i][j] = Matrix.matrix[i + offsetRow][j + offsetCol];
		}
	}
}

float Det(Matrixs &Matrix) {
	if (Matrix.rows == Matrix.cols)
	{
		int det = 0;
		if (Matrix.rows == 1) return Matrix.matrix[0][0];
		if (Matrix.rows == 2) return Matrix.matrix[0][0] * Matrix.matrix[1][1] - Matrix.matrix[0][1] * Matrix.matrix[1][0];
		else
		{
			Matrixs NewMatrix;
			NewMatrix.SetSizeMatrix(Matrix.rows - 1, Matrix.rows - 1);
			for (UINT j = 0; j < Matrix.rows; j++)
			{
				getMatrixMinor(Matrix, 0, j, NewMatrix);
				det += pow(-1, j) * Matrix.matrix[0][j] * Det(NewMatrix);
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

Matrixs ReverseMatrix(Matrixs &Matrix) {
	if (Matrix.rows == Matrix.cols)
	{
		float detMatrix = Det(Matrix);
		if (detMatrix != 0)
		{
			UINT size = Matrix.rows;
			// create new matrix about size diff one
			Matrixs NewMatrix;
			NewMatrix.SetSizeMatrix(size - 1, size - 1);
			Matrixs ReverseMatrix;
			ReverseMatrix.SetSizeMatrix(size, size);
			for (UINT row = 0; row < size; row++)
				for (UINT col = 0; col < size; col++)
				{
					getMatrixMinor(Matrix, row, col, NewMatrix);
					ReverseMatrix.matrix[row][col] = (pow(-1, row + col) * (1 / detMatrix) * Det(NewMatrix));
				}

			return ReverseMatrix.T();
		}
		else
		{
			cout << " Determenant matrix equal to zero!";
			throw 1;
		}
	}
	else
	{
		cout << " The matrix is not square!";
		throw 1;
	}
}