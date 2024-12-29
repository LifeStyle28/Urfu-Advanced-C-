#pragma once
#include <iostream>
#include <vector>


class Matrix
{
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> mat;
public:
    Matrix() = default;
    Matrix(int numRows, int numCols);

    void Reset(int numRows, int numCols);
    int& At(int row, int col);
    const int& At(int row, int col) const;
    int GetRows() const;
    int GetCols() const;

    bool operator==(const Matrix& m2);
    bool operator!=(const Matrix& m2);
    Matrix operator+(const Matrix& m2);

};
