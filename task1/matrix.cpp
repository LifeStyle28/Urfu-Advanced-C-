#include "matrix.hpp"

#include <cstring>
#include <stdexcept>

Matrix::Matrix(int numRows, int numCols)
{
    if (numCols == 0 && numRows == 0)
        throw std::out_of_range("Empty matrix");
    for (int i = 0; i < numRows; ++i)
    {
        matrix_.push_back({});
        for (int j = 0; j < numCols; ++j)
            matrix_[i].push_back(0);
    }
}

void Matrix::Reset(int numRows, int numCols)
{
    int rows = matrix_.size();
    int cols = (matrix_.empty() ? 0 : matrix_[0].size());
    if (numRows > rows || numCols > cols)
    {
        std::string exceptionMsg = "Cannot reset matrix of size " + std::to_string(rows) + "x" + std::to_string(cols) +
                                   + " with " + std::to_string(numRows) + "x" + std::to_string(numCols);
        throw std::out_of_range(exceptionMsg);
    }                       
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            matrix_[i][j] = 0;
        }
    }
}

int& Matrix::At(int row, int col)
{
    int rows = matrix_.size();
    int cols = (matrix_.empty() ? 0 : matrix_[0].size());
    if (row > rows || col > cols)
        throw std::out_of_range("Element is out of matrix range");

    return matrix_[row][col];
}

const int& Matrix::At(int row, int col) const
{
    int rows = matrix_.size();
    int cols = (matrix_.empty() ? 0 : matrix_[0].size());
    if (row > rows || col > cols)
        throw std::out_of_range("Element is out of matrix range");

    return matrix_[row][col];
}

int Matrix::GetRows() const
{
    return matrix_.size();
}

int Matrix::GetCols() const
{
    if (matrix_.empty())
        return 0;

    return matrix_[0].size();
}

bool Matrix::operator==(const Matrix& m2)
{
    int rows = matrix_.size();
    int cols = (matrix_.empty() ? 0 : matrix_[0].size());
    if (rows != m2.GetRows() || cols != m2.GetCols())
        return false;
    bool result = true;
    for (int i = 0; i < rows; ++i)
    {
        result = result && (matrix_[i] == m2.matrix_[i]);
        if (result == false)
            return false;
    }
    return result;
}

bool Matrix::operator!=(const Matrix& m2)
{
    return !((*this) == m2);
}

Matrix Matrix::operator+(const Matrix& m2)
{
    int rows = matrix_.size();
    int cols = (matrix_.empty() ? 0 : matrix_[0].size());
    if (rows != m2.GetRows() || cols != m2.GetCols())
        throw std::invalid_argument("Matrices size aren't match");

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.matrix_[i][j] = matrix_[i][j] + m2.matrix_[i][j];
        }
    }
    return result;
}
