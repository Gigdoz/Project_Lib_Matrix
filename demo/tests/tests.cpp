#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Matrix.h"
#include <iomanip>

TEST_CASE("Operator sum")
{

	Matrix A(3, 4), B(3, 4), C(3, 4);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A(i, j) = 1;
		}
	for (UINT i = 0; i < B.GetRows(); i++)
		for (UINT j = 0; j < B.GetCols(); j++)
		{
			B(i, j) = 2;
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			C(i, j) = 3;
		}
	CHECK(true == (C == A + B));
}

TEST_CASE("Operator deff")
{
	Matrix A(3, 2), B(3, 2), C(3, 2);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A(i, j) = 3;
		}
	for (UINT i = 0; i < B.GetRows(); i++)
		for (UINT j = 0; j < B.GetCols(); j++)
		{
			B(i, j) = 5;
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			C(i, j) = -2;
		}
	CHECK(true == (C == A - B));
}

TEST_CASE("Operator 'in-place' += ")
{
	Matrix A(4, 4), B(4, 4), C(4, 4);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A(i, j) = 3;
		}
	for (UINT i = 0; i < B.GetRows(); i++)
		for (UINT j = 0; j < B.GetCols(); j++)
		{
			B(i, j) = 5;
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			C(i, j) = 8;
		}
	A += B;
	CHECK(true == (C == A));
}

TEST_CASE("Operator 'in-place' -= ")
{
	Matrix A(4, 4), B(4, 4), C(4, 4);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT i = 0; i < A.GetRows(); i++)
			for (UINT j = 0; j < A.GetCols(); j++)
			{
				A(i, j) = 3;
			}
	for (UINT i = 0; i < B.GetRows(); i++)
		for (UINT j = 0; j < B.GetCols(); j++)
		{
			B(i, j) = 5;
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			C(i, j) = -2;
		}
	A -= B;
	CHECK(true == (C == A));
}

TEST_CASE("Operator 'in-place' *= ")
{
	Matrix A(3, 4), B(4, 2), C(3, 2);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT i = 0; i < A.GetRows(); i++)
			for (UINT j = 0; j < A.GetCols(); j++)
			{
				A(i, j) = 3;
			}
	for (UINT i = 0; i < B.GetRows(); i++)
		for (UINT j = 0; j < B.GetCols(); j++)
		{
			B(i, j) = 5;
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			C(i, j) = 60;
		}
	A *= B;
	CHECK(true == (C == A));
}

TEST_CASE("Operator 'in-place' *= (on the number)")
{
	Matrix A(3, 2), C(3, 2);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A(i, j) = 4;
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			C(i, j) = 16;
		}
	A *= 4;
	CHECK(true == (C == A));
}

TEST_CASE("Operator multiplications")
{
	Matrix A(3, 4), B(4, 2), C(3, 2);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A(i, j) = 3;
		}
	for (UINT i = 0; i < B.GetRows(); i++)
		for (UINT j = 0; j < B.GetCols(); j++)
		{
			B(i, j) = 5;
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			C(i, j) = 60;
		}
	CHECK(true == (C == A * B));
}

TEST_CASE("Operator multiplications/ Matrix on vector")
{
	Matrix A(3, 3), x(3, 1), y(3, 1);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A(i, j) = 3;
		}
	for (UINT i = 0; i < x.GetRows(); i++)
		for (UINT j = 0; j < x.GetCols(); j++)
		{
			x(i, j) = 5;
		}
	for (UINT i = 0; i < y.GetRows(); i++)
		for (UINT j = 0; j < y.GetCols(); j++)
		{
			y(i, j) = 45;
		}
	CHECK(true == (y == A * x));
}

TEST_CASE("Operator multiplications on number")
{
	Matrix A(3, 2), C(3, 2);
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A(i, j) = 4;
		}
	for (UINT i = 0; i < C.GetRows(); i++)
		for (UINT j = 0; j < C.GetCols(); j++)
		{
			C(i, j) = 16;
		}
	CHECK(true == (C == A * 4));
}

TEST_CASE("Operator assignment")
{
	Matrix A(4, 3), C;
	for (UINT i = 0; i < A.GetRows(); i++)
		for (UINT j = 0; j < A.GetCols(); j++)
		{
			A(i, j) = 12;
		}
	C = A;
	CHECK(true == (C == A));
}

TEST_CASE("Matrix transposition")
{
	Matrix A(3, 2), B(2, 3);
	A(0, 0) = 2;
	A(0, 1) = 3;
	A(1, 0) = 1;
	A(1, 1) = 4;
	A(2, 0) = 5;
	A(2, 1) = 0;

	B(0, 0) = 2;
	B(0, 1) = 1;
	B(0, 2) = 5;
	B(1, 0) = 3;
	B(1, 1) = 4;
	B(1, 2) = 0;
	CHECK(true == (A.Transposed_matrix() == B));
}

TEST_CASE("Determenant matrix")
{
	Matrix A(3, 3);
	A(0, 0) = 2;
	A(0, 1) = 3;
	A(0, 2) = 3;
	A(1, 0) = 1;
	A(1, 1) = 4;
	A(1, 2) = 4;
	A(2, 0) = 5;
	A(2, 1) = 0;
	A(2, 2) = 7;
	CHECK(A.Det() == 35);
}