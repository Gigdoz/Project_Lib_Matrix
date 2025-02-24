#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.h"
#include "Matrix.h"

TEST_CASE("Error handling 'Out of range!'") {
    Matrix A(3, 2), B(2, 2);
    CHECK_THROWS(B(1, 3) = 3);
    CHECK_THROWS(A(1, 4));
}

TEST_CASE("Matrix | Filling using a list") {
    Matrix A(2, 2);
    A = {1, 2,
         3, 4};
    CHECK(A(0, 0) == 1);
    CHECK(A(0, 1) == 2);
    CHECK(A(1, 0) == 3);
    CHECK(A(1, 1) == 4);

    double s = A(1, 0);
    CHECK(s == 3);
}

TEST_CASE("Vector | Filling using a list") {
    Vector x(4);
    x = {1, 2,
         3, 4};
    CHECK(x(0) == 1);
    CHECK(x(1) == 2);
    CHECK(x(2) == 3);
    CHECK(x(3) == 4);

    double s = x(1);
    CHECK(s == 2);
}

TEST_CASE("Error handling 'The size of the matrices does not match!'") {
    Matrix A(3, 2), B(2, 2);
    A = {2, 3,
         1, 4,
         5, 0};
    
    B = {2, 1,
         5, 3};

    CHECK_FALSE(A == B);
    CHECK_THROWS(A += B);
    CHECK_THROWS(A -= B);
}

TEST_CASE("Error handling 'The rows and columns of the matrices does not match!'") {
    Matrix A(3, 1), B(2, 3);
    A = {2, 1, 5};

    B = {2, 1, 3,
         5, 3, 6};

    CHECK_THROWS(A * B);
}

TEST_CASE("Operator addition/Operator 'in-place' += ") {
    Matrix A(3, 2), B(3, 2), C(3, 2);
    A = {2, 3,
         1, 4,
         5, 0};

    B = {2, 1,
         5, 3,
        4, 0};

    C = {4, 4,
         6, 7,
         9, 0};

    CHECK(C == A + B);
    A += B;
    CHECK(C == A);
}

TEST_CASE("Operator deff/Operator 'in-place' -=") {
    Matrix A(3, 2), B(3, 2), C(3, 2);
    A = {2, 3,
         1, 4,
         5, 0};

    B = {2, 1,
         5, 3,
         4, 0};

    C = {0, 2,
         -4, 1,
         1, 0};

    CHECK(C == A - B);
    A -= B;
    CHECK(C == A);
}

TEST_CASE("Matrix | operator multiplication/Operator 'in-place' | */*=") {
    Matrix A(3, 2), B(2, 3), C(3, 3);
    A = {2, 3,
         1, 4,
         5, 0};

    B = {2, 1, 3,
         5, 3, 6};

    C = {19, 11, 24,
         22, 13, 27,
         10, 5, 15};

    CHECK(C == A * B);
    A *= B;
    CHECK(C == A);
}

TEST_CASE("Matrix multiplied by Vector | Vector multiplied by Vector") {
    Matrix C(3, 3);
    Vector x(3), y(3);
    x = {1, 2, 3};
    y = {113, 129, 65};

    C = {19, 11, 24,
        22, 13, 27,
        10, 5, 15};
    CHECK(y == C * x);

    C = {113, 129, 65,
        226, 258, 130,
        339, 387, 195};

    CHECK(C == x * y.transpose());
}

TEST_CASE("Vector operator dot | Vector multiplied by Vector solution scaler") {
    Vector x(3), y(3);
    x = {1, 2, 3};
    y = {113, 129, 65};
    CHECK(y.dot(x) == 566);

    double sc = (x.transpose() * y)(0, 0);
    CHECK(sc == 566);
}

TEST_CASE("Operator multiplications on number/Operator 'in-place' *= (on the number)") {
    Matrix A(3, 2), C(3, 2);

    A = {2, 3,
         1, 4,
         5, 0};

    C = {8, 12,
         4, 16,
         20, 0};     

    CHECK(C == A * 4);
    A *= 4;
    CHECK(C == A);
}

TEST_CASE("Operator assignment") {
    Matrix A(3, 2), C(3, 2);
    A = {2, 3,
         1, 4,
         5, 0};

    C = A;
    CHECK(C == A);
}

TEST_CASE("Matrix transposition") {
    Matrix A(3, 2), B(2, 3);
    A = {2, 3,
         1, 4,
         5, 0};

    B = {2, 1, 5,
         3, 4, 0};

    CHECK(B == A.transpose());
}

TEST_CASE("Vector | operator norm") {
    Vector x(4);
    x = {2.3, 4.2, 5.6, 0.1};

    CHECK(pow(x.norm(), 2) == 54.3);
}

TEST_CASE("Matrix ToString") {
    Matrix A(3, 2);
    Vector x(3);

    x = {1, 2, 3};

    A = {2, 3,
        1, 4,
        5, 0};

    std::cout << A;
    std::cout << x.transpose();
}
