#include "Matrix.h"
#include <math.h>

Matrix::Matrix(UINT rows, UINT cols, std::initializer_list<double> data)
    : data_(data),
    rows_(rows),
    cols_(cols) {
    if (data.size() != rows * cols) {
        throw std::invalid_argument("The size of the lists does not match!");
    }
}

double &Matrix::operator()(UINT row, UINT col) {
    if (row >= this->rows_ || col >= this->cols_) {
        throw std::out_of_range("Out of range!");
    }
    return this->data_[cols_ * row + col];
}

double Matrix::operator()(UINT row, UINT col) const {
    if (row >= this->rows_ || col >= this->cols_) {
        throw std::out_of_range("Out of range!");
    }
    return this->data_[cols_ * row + col];
}

Matrix& Matrix::operator=(std::initializer_list<double> data) {
    if (data_.size() != data.size()) {
        throw std::invalid_argument("The size of the lists does not match!");
    }
    data_ = data;
    return *this;
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
    if (other.rows_ != this->cols_) {
        throw std::invalid_argument("The rows and columns of the matrices does not match!");
    }

    Matrix result(this->rows_, other.cols_);
    for (UINT i = 0; i < this->rows_; i++) {
        for (UINT j = 0; j < other.cols_; j++) {
            for (UINT k = 0; k < this->cols_; k++) {
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

Matrix Matrix::operator/(double s) {
    Matrix result(*this);
    return result /= s;
}

Matrix &Matrix::operator+=(const Matrix &other) {
    if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
        throw std::invalid_argument("The size of the matrices does not match!");
    }

    for (UINT i = 0; i < this->rows_; i++) {
        for (UINT j = 0; j < this->cols_; j++) {
            this->data_[cols_ * i + j] += other.data_[cols_ * i + j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &other) {
    if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
        throw std::invalid_argument("The size of the matrices does not match!");
    }

    for (UINT i = 0; i < this->rows_; i++) {
        for (UINT j = 0; j < this->cols_; j++) {
            this->data_[cols_ * i + j] -= other.data_[cols_ * i + j];
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &other) {
    return *this = *this * other;
}

Matrix &Matrix::operator*=(double s) {
    for (UINT i = 0; i < rows_; i++) {
        for (UINT j = 0; j < cols_; j++) {
            this->data_[cols_ * i + j] *= s;
        }
    }
    return *this;
}

Matrix &Matrix::operator/=(double s) {
    for (UINT i = 0; i < rows_; i++) {
        for (UINT j = 0; j < cols_; j++) {
            this->data_[cols_ * i + j] /= s;
        }
    }
    return *this;
}

bool Matrix::operator==(const Matrix &other) const {
    if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
        return false;
    }

    for (UINT i = 0; i < this->rows_; i++) {
        for (UINT j = 0; j < this->cols_; j++) {
            if (this->data_[cols_ * i + j] != other.data_[other.cols_ * i + j]) {
                return false;
            }
        }
    }
    return true;
}

Matrix Matrix::transpose() {
    Matrix transposed(cols_, rows_);
    for (UINT i = 0; i < cols_; i++) {
        for (UINT j = 0; j < rows_; j++) {
            transposed.data_[transposed.cols_ * i + j] = this->data_[cols_ * j + i];
        }
    }
    return transposed;
}

std::ostream &operator<<(std::ostream &out, const Matrix &other) {
    out << std::endl;
    for (int row = 0; row < other.rows(); row++) {
        for (int col = 0; col < other.cols(); col++) {
            out << "[" << other(row, col) << "] ";
        }
        out << std::endl;
    }

    return out;
}

Vector Vector::cross(const Vector& other) {
    if (this->rows() != 3 || other.rows() != 3) {
        throw std::invalid_argument("Cross product is only for vectors of size 3!");
    }
    Vector result(3);
    result(0) = (*this)(1) * other(2) - (*this)(2) * other(1);
    result(1) = (*this)(2) * other(0) - (*this)(0) * other(2);
    result(2) = (*this)(0) * other(1) - (*this)(1) * other(0);

    return result;
}

double Vector::norm() const {
    double squad = 0.0;
    for (int i = 0; i < this->rows(); i++) {
        squad += (*this)(i) * (*this)(i);
    }
    return std::sqrt(squad);
}
