#pragma once
#include <stdexcept>
#include <vector>
class Matrix
{
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
private:
    std::vector<std::vector<int>> mass;
};
