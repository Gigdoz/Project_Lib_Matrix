#include "Matrix.h"

UINT Matrix::getRows() const {
    return this->rows;
}

UINT Matrix::getCols() const {
    return this->cols;
}

double &Matrix::operator()(UINT row, UINT col) {
    if (row >= this->rows || col >= this->cols) {
        throw std::out_of_range("Out of range!");
    }
    return this->data[cols * row + col];
}

double Matrix::operator()(UINT row, UINT col) const {
    if (row >= this->rows || col >= this->cols) {
        throw std::out_of_range("Out of range!");
    }
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
    if (other.rows != this->cols) {
        throw std::invalid_argument("The rows and columns of the matrices does not match!");
    }

    Matrix result(this->rows, other.cols);
    for (UINT i = 0; i < this->rows; i++) {
        for (UINT j = 0; j < other.cols; j++) {
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
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("The size of the matrices does not match!");
    }

    for (UINT i = 0; i < this->rows; i++) {
        for (UINT j = 0; j < this->cols; j++) {
            this->data[cols * i + j] += other.data[cols * i + j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &other) {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("The size of the matrices does not match!");
    }

    for (UINT i = 0; i < this->rows; i++) {
        for (UINT j = 0; j < this->cols; j++) {
            this->data[cols * i + j] -= other.data[cols * i + j];
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
            this->data[cols * i + j] *= s;
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
            if (this->data[cols * i + j] != other.data[other.cols * i + j]) {
                return false;
            }
        }
    }
    return true;
}

Matrix Matrix::transpose() {
    Matrix transposed(cols, rows);
    for (UINT i = 0; i < cols; i++) {
        for (UINT j = 0; j < rows; j++) {
            transposed.data[transposed.cols * i + j] = this->data[cols * j + i];
        }
    }
    return transposed;
}

std::ostream &operator<<(std::ostream &out, const Matrix &other) {
    out << std::endl;
    for (int row = 0; row < other.getRows(); row++) {
        for (int col = 0; col < other.getCols(); col++) {
            out << "[" << other(row, col) << "] ";
        }
        out << std::endl;
    }

    return out;
}
