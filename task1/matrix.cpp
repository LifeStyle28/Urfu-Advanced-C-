#include "matrix.hpp"
#include <stdexcept>
#include <vector>

// Конструктор с параметрами
Matrix::Matrix(int numRows, int numCols) {
    Reset(numRows, numCols);
}

// Метод для сброса размеров матрицы
void Matrix::Reset(int numRows, int numCols) {
    if (numRows <= 0 || numCols <= 0) {
        rows_ = 0;
        cols_ = 0;
        data_.clear();
    } else {
        rows_ = numRows;
        cols_ = numCols;
        data_.resize(rows_, std::vector<int>(cols_, 0));
    }
}

// Метод для доступа к элементам матрицы (неконстантный)
int& Matrix::At(int row, int col) {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[row][col];
}

// Метод для доступа к элементам матрицы (константный)
const int& Matrix::At(int row, int col) const {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[row][col];
}

// Метод для получения количества строк
int Matrix::GetRows() const {
    return rows_;
}

// Метод для получения количества столбцов
int Matrix::GetCols() const {
    return cols_;
}

// Оператор сравнения на равенство
bool Matrix::operator==(const Matrix& m2) {
    if (rows_ != m2.rows_ || cols_ != m2.cols_) {
        return false;
    }
    return data_ == m2.data_;
}

// Оператор сравнения на неравенство
bool Matrix::operator!=(const Matrix& m2) {
    return !(*this == m2);
}

// Оператор сложения матриц
Matrix Matrix::operator+(const Matrix& m2) {
    if (rows_ != m2.rows_ || cols_ != m2.cols_) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }

    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result.At(i, j) = At(i, j) + m2.At(i, j);
        }
    }
    return result;
}
