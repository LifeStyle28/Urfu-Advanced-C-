#include "matrix.hpp"

#include <stdexcept>

Matrix::Matrix(int numRows, int numCols)
{
    Reset(numRows, numCols);
}

void Matrix::Reset(int numRows, int numCols)
{
    if (numRows <= 0 || numCols <= 0) 
    {
        mass.clear();
        return;
    }
    mass.resize(numRows, std::vector<int>(numCols, 0));
}

int& Matrix::At(int row, int col)
{
    // your implementation here
}

const int& Matrix::At(int row, int col) const
{
    if (row < 0 || row >= GetRows() || col < 0 || col >= GetCols()) 
    {
        throw std::out_of_range("out of range");
    }
    return mass[row][col];
}

int Matrix::GetRows() const
{
    return mass.size();
}

int Matrix::GetCols() const
{
    if (mass.empty()) 
    {
        return 0;
    }
    else 
    {
        return mass[0].size();
    }
}

bool Matrix::operator==(const Matrix& m2)
{
    if (GetRows() != m2.GetRows() || GetCols() != m2.GetCols()) 
    {
        return false;
    }
    for (size_t i = 0; i < GetRows(); ++i) 
    {
        if (!std::equal(mass[i].begin(), mass[i].end(), m2.mass[i].begin())) 
        {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& m2)
{
    bool Matrix::operator!=(const Matrix& m2) 
    {
        return !(*this == m2);
    }
}

Matrix Matrix::operator+(const Matrix& m2)
{
    if (GetRows() != m2.GetRows() || GetCols() != m2.GetCols()) 
    {
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }
    Matrix result(GetRows(), GetCols());
    for (size_t i = 0; i < GetRows(); ++i) 
    {
        for (size_t j = 0; j < GetCols(); ++j) 
        {
            result.At(i, j) = At(i, j) + m2.At(i, j);
        }
    }
    return result;
}
