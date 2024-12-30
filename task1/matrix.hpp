#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
public:
    Matrix() : row_count(0), col_count(0) {}
    explicit Matrix(int height, int width);

    Matrix(const Matrix& other) = default;
    Matrix& operator=(const Matrix& other) = default;

    Matrix(Matrix&& other) noexcept : row_count(other.row_count), col_count(other.col_count), data(std::move(other.data)) {
        other.row_count = 0;
        other.col_count = 0;
    }
    Matrix& operator=(Matrix&& other) noexcept {
        if (this != &other) {
            row_count = other.row_count;
            col_count = other.col_count;
            data = std::move(other.data);
            other.row_count = 0;
            other.col_count = 0;
        }
        return *this;
    }

    void Reset(int height, int width);
    int At(int row_idx, int col_idx) const;
    int& At(int row_idx, int col_idx);
    int GetRows() const;
    int GetCols() const;

    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
    friend bool operator!=(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);

private:
    int row_count;
    int col_count;
    std::vector<std::vector<int>> data;
};
