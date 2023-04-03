#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Matrix.h"
#include <iomanip>

TEST_CASE("Operator sum/Operator 'in-place' +=")
{
	Matrix A(3, 2), B(3, 2), C(3, 2), f;
	A(0, 0) = 2;
	A(0, 1) = 3;
	A(1, 0) = 1;
	A(1, 1) = 4;
	A(2, 0) = 5;
	A(2, 1) = 0;

	B(0, 0) = 2;
	B(0, 1) = 1;
	B(1, 0) = 5;
	B(1, 1) = 3;
	B(2, 0) = 4;
	B(2, 1) = 0;

	C(0, 0) = 4;
	C(0, 1) = 4;
	C(1, 0) = 6;
	C(1, 1) = 7;
	C(2, 0) = 9;
	C(2, 1) = 0;
	CHECK(true == (C == A + B));
	A += B;
	CHECK(true == (C == A));
}

TEST_CASE("Operator deff/Operator 'in-place' -=")
{
	Matrix A(3, 2), B(3, 2), C(3, 2);
	A(0, 0) = 2;
	A(0, 1) = 3;
	A(1, 0) = 1;
	A(1, 1) = 4;
	A(2, 0) = 5;
	A(2, 1) = 0;

	B(0, 0) = 2;
	B(0, 1) = 1;
	B(1, 0) = 5;
	B(1, 1) = 3;
	B(2, 0) = 4;
	B(2, 1) = 0;

	C(0, 0) = 0;
	C(0, 1) = 2;
	C(1, 0) = -4;
	C(1, 1) = 1;
	C(2, 0) = 1;
	C(2, 1) = 0;
	CHECK(true == (C == A - B));
	A -= B;
	CHECK(true == (C == A));
}

TEST_CASE("Operator multiplications/Operator 'in-place' *= ")
{
	Matrix A(3, 2), B(2, 3), C(3, 3);
	A(0, 0) = 2;
	A(0, 1) = 3;
	A(1, 0) = 1;
	A(1, 1) = 4;
	A(2, 0) = 5;
	A(2, 1) = 0;

	B(0, 0) = 2;
	B(0, 1) = 1;
	B(0, 2) = 3;
	B(1, 0) = 5;
	B(1, 1) = 3;
	B(1, 2) = 6;

	C(0, 0) = 19;
	C(0, 1) = 11;
	C(0, 2) = 24;
	C(1, 0) = 22;
	C(1, 1) = 13;
	C(1, 2) = 27;
	C(2, 0) = 10;
	C(2, 1) = 5;
	C(2, 2) = 15;
	CHECK(true == (C == A * B));
	A *= B;
	CHECK(true == (C == A));
}

TEST_CASE("Operator multiplications on number/Operator 'in-place' *= (on the number)")
{
	Matrix A(3, 2),  C(3, 2);
	A(0, 0) = 2;
	A(0, 1) = 3;
	A(1, 0) = 1;
	A(1, 1) = 4;
	A(2, 0) = 5;
	A(2, 1) = 0;

	C(0, 0) = 8;
	C(0, 1) = 12;
	C(1, 0) = 4;
	C(1, 1) = 16;
	C(2, 0) = 20;
	C(2, 1) = 0;
	CHECK(true == (C == A * 4));
	A *= 4;
	CHECK(true == (C == A));
}

TEST_CASE("Operator assignment")
{
	Matrix A(3, 2), C(3, 2);
	A(0, 0) = 2;
	A(0, 1) = 3;
	A(1, 0) = 1;
	A(1, 1) = 4;
	A(2, 0) = 5;
	A(2, 1) = 0;
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
	CHECK(B == A.TransposedMatrix());
}

TEST_CASE("Determenant matrix")
{
	Matrix A(4, 4);
	A(0, 0) = 2;
	A(0, 1) = 3;
	A(0, 2) = 3;
	A(0, 3) = 1;
	A(1, 0) = 1;
	A(1, 1) = 4;
	A(1, 2) = 4;
	A(1, 3) = 2;
	A(2, 0) = 5;
	A(2, 1) = 0;
	A(2, 2) = 7;
	A(2, 3) = 3;
	A(3, 0) = 4;
	A(3, 1) = 2;
	A(3, 2) = 1;
	A(3, 3) = 1;
	CHECK((int)A.Det() == 74);
}