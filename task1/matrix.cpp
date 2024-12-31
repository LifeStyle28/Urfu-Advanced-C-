#include "matrix.hpp"
#include <cstring>
#include <stdexcept>
#include <vector>

Matrix::Matrix(int numRows, int numCols) {
    matrix_.resize(numRows, std::vector<int>(numCols, 0));
}

void Matrix::Reset(int numRows, int numCols) {
    if (numRows < 0 || numCols < 0) {
        throw std::invalid_argument("Number of rows and columns must be non-negative");
    }

    if (numRows > GetRows() || numCols > GetCols()) {
        throw std::out_of_range("Cannot reset matrix size larger than current dimensions");
    }

    for (int i = 0; i < numRows; ++i) {
        std::fill(matrix_[i].begin(), matrix_[i].begin() + numCols, 0);
    }
}

int& Matrix::At(int row, int col) {
    if (row < 0 || row >= GetRows() || col < 0 || col >= GetCols()) {
        throw std::out_of_range("Element is out of matrix range");
    }
    return matrix_[row][col];
}

const int& Matrix::At(int row, int col) const {
    if (row < 0 || row >= GetRows() || col < 0 || col >= GetCols()) {
        throw std::out_of_range("Element is out of matrix range");
    }
    return matrix_[row][col];
}

int Matrix::GetRows() const {
    return matrix_.size();
}

int Matrix::GetCols() const {
    return matrix_.empty() ? 0 : matrix_[0].size();
}

bool Matrix::operator==(const Matrix& m2) const {
    if (GetRows() != m2.GetRows() || GetCols() != m2.GetCols()) {
        return false;
    }
    return matrix_ == m2.matrix_;
}

bool Matrix::operator!=(const Matrix& m2) const {
    return !(*this == m2);
}

Matrix Matrix::operator+(const Matrix& m2) const {
    if (GetRows() != m2.GetRows() || GetCols() != m2.GetCols()) {
        throw std::invalid_argument("Matrices sizes do not match");
    }

    Matrix result(GetRows(), GetCols());
    for (int i = 0; i < GetRows(); ++i) {
        for (int j = 0; j < GetCols(); ++j) {
            result.At(i, j) = At(i, j) + m2.At(i, j);
        }
    }
    return result;
}
