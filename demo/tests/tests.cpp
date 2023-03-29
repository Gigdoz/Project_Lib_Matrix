#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Matrix.h"
#include <iomanip>

TEST_CASE("Operator sum")
{

	float value;
	Matrix A(3, 4), B(3, 4), C(3, 4);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			value = 1;
			A.InputElementMatrix(value, i, j);
		}
	for (UINT i = 0; i < B.GetRows(); i++)
		for (UINT j = 0; j < B.GetCols(); j++)
		{
			value = 2;
			B.InputElementMatrix(value, i, j);
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			value = 3;
			C.InputElementMatrix(value, i, j);
		}
	CHECK(true == (C == A + B));
}

TEST_CASE("Operator deff")
{
	float value;
	Matrix A(3, 2), B(3, 2), C(3, 2);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			value = 3;
			A.InputElementMatrix(value, i, j);
		}
	for (UINT i = 0; i < B.GetRows(); i++)
		for (UINT j = 0; j < B.GetCols(); j++)
		{
			value = 5;
			B.InputElementMatrix(value, i, j);
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			value = -2;
			C.InputElementMatrix(value, i, j);
		}
	CHECK(true == (C == A - B));
}

TEST_CASE("Operator in-place")
{
	float value;
	Matrix A(4, 4), B(4, 4), C(4, 4);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			value = 3;
			A.InputElementMatrix(value, i, j);
		}
	for (UINT i = 0; i < B.GetRows(); i++)
		for (UINT j = 0; j < B.GetCols(); j++)
		{
			value = 5;
			B.InputElementMatrix(value, i, j);
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			value = 8;
			C.InputElementMatrix(value, i, j);
		}
	A += B;
	CHECK(true == (C == A));
}

TEST_CASE("Operator multiplications")
{
	Matrix A(3, 4), B(4, 2), C(3, 2);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A.InputElementMatrix(3, i, j);
		}
	for (UINT i = 0; i < B.GetRows(); i++)
		for (UINT j = 0; j < B.GetCols(); j++)
		{
			B.InputElementMatrix(5, i, j);
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			C.InputElementMatrix(60, i, j);
		}
	CHECK(true == (C == A * B));
}

TEST_CASE("Operator multiplications/ Matrix on vector")
{
	Matrix A(3, 3), x(3, 1), y(3, 1);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A.InputElementMatrix(3, i, j);
		}
	for (UINT i = 0; i < x.GetRows(); i++)
		for (UINT j = 0; j < x.GetCols(); j++)
		{
			x.InputElementMatrix(5, i, j);
		}
	for (UINT i = 0; i < y.GetRows(); i++)
		for (UINT j = 0; j < y.GetCols(); j++)
		{
			y.InputElementMatrix(45, i, j);
		}
	CHECK(true == (y == A * x));
}

TEST_CASE("Operator multiplications on number")
{
	Matrix A(3, 2), C(3, 2);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A.InputElementMatrix(4, i, j);
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			C.InputElementMatrix(16, i, j);
		}
	CHECK(true == (C == A * 4));
}

TEST_CASE("Operator assignment")
{
	Matrix A(4, 3), C;
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A.InputElementMatrix(10, i, j);
		}
	C = A;
	CHECK(true == (C == A));
}

TEST_CASE("Matrix transposition")
{
	Matrix A(3, 2), B(2, 3);
	A.InputElementMatrix(2, 0, 0);
	A.InputElementMatrix(3, 0, 1);
	A.InputElementMatrix(1, 1, 0);
	A.InputElementMatrix(4, 1, 1);
	A.InputElementMatrix(5, 2, 0);
	A.InputElementMatrix(0, 2, 1);

	B.InputElementMatrix(2, 0, 0);
	B.InputElementMatrix(1, 0, 1);
	B.InputElementMatrix(5, 0, 2);
	B.InputElementMatrix(3, 1, 0);
	B.InputElementMatrix(4, 1, 1);
	B.InputElementMatrix(0, 1, 2);
	CHECK(true == (A.T() == B));
}

TEST_CASE("Determenant matrix")
{
	Matrix A(3, 3);
	A.InputElementMatrix(2, 0, 0);
	A.InputElementMatrix(3, 0, 1);
	A.InputElementMatrix(3, 0, 2);
	A.InputElementMatrix(1, 1, 0);
	A.InputElementMatrix(4, 1, 1);
	A.InputElementMatrix(4, 1, 2);
	A.InputElementMatrix(5, 2, 0);
	A.InputElementMatrix(0, 2, 1);
	A.InputElementMatrix(7, 2, 2);
	CHECK(Det(A) == 35);
}