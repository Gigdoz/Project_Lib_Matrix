#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "Matrix.h"

TEST_CASE("Error handling 'Out of range!'") {
    Matrix A(3, 2), B(2, 2);
    CHECK_THROWS(B(1, 3) = 3);
    CHECK_THROWS(A(1, 4));
}

TEST_CASE("Error handling 'The size of the matrices does not match!'") {
    Matrix A(3, 2), B(2, 2);
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
    CHECK_FALSE(A == B);
    CHECK_THROWS(A += B);
    CHECK_THROWS(A -= B);
}

TEST_CASE("Error handling 'The rows and columns of the matrices does not match!'") {
    Matrix A(3, 1), B(2, 3);
    A(0, 0) = 2;
    A(1, 0) = 1;
    A(2, 0) = 5;

    B(0, 0) = 2;
    B(0, 1) = 1;
    B(0, 2) = 3;
    B(1, 0) = 5;
    B(1, 1) = 3;
    B(1, 2) = 6;

    CHECK_THROWS(A * B);
}

TEST_CASE("Operator addition/Operator 'in-place' += ") {
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

    C(0, 0) = 4;
    C(0, 1) = 4;
    C(1, 0) = 6;
    C(1, 1) = 7;
    C(2, 0) = 9;
    C(2, 1) = 0;
    CHECK(C == A + B);
    A += B;
    CHECK(C == A);
}

TEST_CASE("Operator deff/Operator 'in-place' -=") {
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
    CHECK(C == A - B);
    A -= B;
    CHECK(C == A);
}

TEST_CASE("Operator multiplication/Operator 'in-place' *=  and scalar product") {
    Matrix A(3, 2), B(2, 3), C(3, 3);
    Vector x(3), y(3);
    x(0) = 1;
    x(1) = 2;
    x(2) = 3;

    y(0) = 113;
    y(1) = 129;
    y(2) = 65;

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

    CHECK(y == C * x);
    CHECK(C == A * B);
    A *= B;
    CHECK(C == A);

    C(0, 0) = 113;
    C(0, 1) = 129;
    C(0, 2) = 65;
    C(1, 0) = 226;
    C(1, 1) = 258;
    C(1, 2) = 130;
    C(2, 0) = 339;
    C(2, 1) = 387;
    C(2, 2) = 195;
    CHECK(C == x * y.transpose());

    Matrix sc = x.transpose() * y;
    CHECK(sc(0, 0) == 566);

    CHECK(y.dot(x) == 566);
}

TEST_CASE("Operator multiplications on number/Operator 'in-place' *= (on the number)") {
    Matrix A(3, 2), C(3, 2);
    Vector s;
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
    CHECK(C == A * 4);
    A *= 4;
    CHECK(C == A);
}

TEST_CASE("Operator assignment") {
    Matrix A(3, 2), C(3, 2);
    A(0, 0) = 2;
    A(0, 1) = 3;
    A(1, 0) = 1;
    A(1, 1) = 4;
    A(2, 0) = 5;
    A(2, 1) = 0;
    C = A;
    CHECK(C == A);
}

TEST_CASE("Matrix transposition") {
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
    CHECK(B == A.transpose());
}

TEST_CASE("Matrix ToString") {
    Matrix A(3, 2);
    Vector x(3);

    x(0) = 1;
    x(1) = 2;
    x(2) = 3;

    A(0, 0) = 2;
    A(0, 1) = 3;
    A(1, 0) = 1;
    A(1, 1) = 4;
    A(2, 0) = 5;
    A(2, 1) = 0;

    std::cout << A;
    std::cout << x.transpose();
}
