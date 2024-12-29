#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>


class Matrix
{
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> mat;
public:
     Matrix() : rows(0), cols(0) {}
    explicit Matrix(int numRows, int numCols);
    
    Matrix(const Matrix& other) = default;
    Matrix& operator=(const Matrix& other) = default;
    
    Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), mat(std::move(other.mat)) {
        other.rows = 0;
        other.сols = 0;
    }
    Matrix& operator=(Matrix&& other) noexcept {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            mat = std::move(other.mat);
            other.rows = 0;
            other.cols = 0;
        }
        return *this;
    }

    void Reset(int numRows, int numCols);
    int At(int row, int col) const;
    int& At(int row, int col);
    int GetRows() const;
    int GetCols() const;

    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
    friend bool operator!=(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
};
