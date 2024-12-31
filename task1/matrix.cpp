#include "matrix.hpp"

#include <stdexcept>

Matrix::Matrix(int numRows, int numCols)
{
    Reset(numRows, numCols);
}

void Matrix::Reset(int numRows, int numCols)
{
    if (numRows == 0 || numCols == 0) 
    {
        row = col = 0;
    }
}

int& Matrix::At(int row, int col)
{
    if (row < 0 || row >=numRows  || col < 0 || col >= numCols) 
    {
        throw std::out_of_range;
    }
}

const int& Matrix::At(int row, int col) const
{
    if (row < 0 || row >=numRows  || col < 0 || col >= numCols) 
    {
        throw std::out_of_range;
    }
}

int Matrix::GetRows() const
{
    return numRows;
}

int Matrix::GetCols() const
{
    return numCols;
}

bool Matrix::operator==(const Matrix& m2)
{
    return  == m2.numRows && cols == m2.numCols && data == m2.data;
}

bool Matrix::operator!=(const Matrix& m2)
{
    return !(*this == m2);
}

Matrix Matrix::operator+(const Matrix& m2)
{
    if (row != m2.numRows || col != m2.numCols)
    {
        throw std::invalid_argument;
    }
}
