
#include "Matrix.h"

using namespace std;

namespace {
    void throwIfOutOfRange(const Matrix &other, UINT row, UINT col) {
        if (row >= other.getRows() || col >= other.getCols()) {
            throw out_of_range("Out of range!");
        }
    }

    void throwIfMatricesSizeDoesNotMatch(const Matrix &a, const Matrix &b) {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
            throw invalid_argument("The size of the matrices does not match!");
        }
    }

    void throwIfMatricesRowsAndColumnsDoesNotMatch(const Matrix &a, const Matrix &b) {
        if (b.getRows() != a.getCols()) {
            throw invalid_argument("The rows and columns of the matrices does not match!");
        }
    }
}

UINT Matrix::getRows() const {
    return this->rows;
}

UINT Matrix::getCols() const {
    return this->cols;
}

double&Matrix::operator()(UINT row, UINT col) {
    throwIfOutOfRange(*this, row, col);
    return this->data[cols * row + col];
}

double Matrix::operator()(UINT row, UINT col) const {
    throwIfOutOfRange(*this, row, col);
    return this->data[cols * row + col];
}

Matrix Matrix::operator+(const Matrix &other) {
    Matrix result(*this);
    return result += other;
}

Matrix Matrix::operator-(const Matrix &other) {
    Matrix result(*this);
    return result -= other;
}

Matrix Matrix::operator*(const Matrix &other) {
    throwIfMatricesRowsAndColumnsDoesNotMatch(*this, other);
    Matrix result(this->rows, other.getCols());
    for (UINT i = 0; i < this->rows; i++) {
        for (UINT j = 0; j < other.getCols(); j++) {
            for (UINT k = 0; k < this->cols; k++) {
                result(i, j) += (*this)(i, k) * other(k, j);
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(double s) {
    Matrix result(*this);
    return result *= s;
}

Matrix &Matrix::operator+=(const Matrix &other) {
    throwIfMatricesSizeDoesNotMatch(*this, other);
    for (UINT row = 0; row < this->rows; row++) {
        for (UINT col = 0; col < this->cols; col++) {
            (*this)(row, col) += other(row, col);
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &other) {
    throwIfMatricesSizeDoesNotMatch(*this, other);
    for (UINT row = 0; row < this->rows; row++) {
        for (UINT col = 0; col < this->cols; col++) {
            (*this)(row, col) -= other(row, col);
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &other) {
    return *this = *this * other;
}

Matrix &Matrix::operator*=(double s) {
    for (UINT i = 0; i < rows; i++) {
        for (UINT j = 0; j < cols; j++) {
            (*this)(i, j) *= s;
        }
    }
    return *this;
}

bool Matrix::operator==(const Matrix &other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        return false;
    }

    for (UINT i = 0; i < this->rows; i++) {
        for (UINT j = 0; j < this->cols; j++) {
            if (this->data[rows * j + i] != other.data[other.rows * j + i]) {
                return false;
            }
        }
    }
    return true;
}

Matrix Matrix::transposedMatrix() {
    Matrix Transpose(cols, rows);
    for (UINT i = 0; i < cols; i++) {
        for (UINT j = 0; j < rows; j++) {
            Transpose(i, j) = (*this)(j, i);
        }
    }
    return Transpose;
}

ostream &operator<<(ostream &out, const Matrix &other) {
    out << endl;
    for (int row = 0; row < other.getRows(); row++) {
        for (int col = 0; col < other.getCols(); col++) {
            out << "[" << other(row, col) << "] ";
        }
        out << endl;
    }

    return out;
}

double scalerProduct(const Vector &vector_first, const Vector &vector_second)
{
    Vector vector = vector_first;
    Matrix sc = vector.transposedMatrix() * vector_second;
    return sc(0,0);
}
