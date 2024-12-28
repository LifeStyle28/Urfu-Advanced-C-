#include "matrix.hpp"

#include <stdexcept>

Matrix::Matrix(int numRows, int numCols)
{
    if (numRows < 0 || numCols < 0) {
        throw out_of_range("");
    }
    if (numRows == 0 || numCols == 0) {
        x = 0;
        y = 0;
        Z.clear();
    }
    else {
        x = numRows;
        y = numCols;
        Z.assign(x, vector<int>(y, 0));
    }
}

void Matrix::Reset(int numRows, int numCols)
{
    if (numRows < 0 || numCols < 0) 
    {
        throw out_of_range("");
    }
    if (numRows == 0 || numCols == 0) 
    {
        x = 0;
        y = 0;
        Z.clear();
    }
    else 
    {
        x = numRows;
        y = numCols;
        Z.assign(x, vector<int>(y, 0));
    }
}

int& Matrix::At(int row, int col)
{
    if (row < 0 || row >= x || col < 0 || col >= y) 
    {
        throw out_of_range("");
    }
    return Z[row][col];
}

const int& Matrix::At(int row, int col) const
{
    if (row < 0 || row >= x || col < 0 || col >= y)
    {
        throw out_of_range("");
    }
    return Z[row][col];
}

int Matrix::GetRows() const
{
    return x;
}

int Matrix::GetCols() const
{
    return y;
}

bool Matrix::operator==(const Matrix& m2)
{
    if (x!=m2.GetRows() || y != m2.GetCols())
    {
        return false;
    }
    else
    {
        int i = 0, j=0;
        bool b = true;
        for (i; i < x; ++i)
        {
            for (j; j < y; ++j)
            {
                if (Z[i][j] != m2.At(i, j))
                {
                    b = false;
                    break;
                }
            }
        }   
        return b;
    }
}

bool Matrix::operator!=(const Matrix& m2)
{
    return not(this->operator==(m2));
}

Matrix Matrix::operator+(const Matrix& m2)
{
    if (x == m2.GetRows() && y == m2.GetCols())
    {
        int i = 0, j = 0;
        for (i; i < x; ++i)
        {
            for (j; j < y; ++j)
            {
                Z[i][j] += m2.At(i, j);
            }
        };
    }
    else
    {
        throw invalid_argument("");
    }
}
