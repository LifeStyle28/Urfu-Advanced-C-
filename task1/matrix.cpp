#include "matrix.hpp"
#include <iostream>
#include <vector>
#include <cerr>
using namespace std;

Matrix::Matrix(int numRows, int numCols)
{
	//вывод ошибок
	if (numRows < 0)
    	{
		cerr<<"Произошла ошибка -> количество строк не может быть меньше нуля";
    	}
   	if (numCols < 0)
	{
		cerr<<"Произошла ошибка -> количество столбцев не может быть меньше нуля";
    	}

	//при нуле строк или столбцев, или всё вместе
	if (numRows == 0 || numCols == 0)
	{
		rows = 0;
		cols = 0;
		
	} 
	else
	{
		rows = numRows;
		cols = numCols;
	}
}

void Matrix::Reset(int numRows, int numCols)
{
    mat.resize(0);
    vector<int> l(NULL, numCols);
    for (int i = 0; i < numRows - 1; i++)
    {
	    mat.push_back(l);
    }
}

int& Matrix::At(int row, int col)
{
    try
    {
    	return mat[row][col];
    }
    catch (out_of_range)
    {
    	cout << "Out of range: referring to element (" << row << ", " << col << "), but matrix size is " << mat.size() << "x" << mat[0].size();
    }
}

const int& Matrix::At(int row, int col) const
{
    try
    {
    	return mat[row][col];
    }
    catch (out_of_range)
    {
    	cout << "Out of range: referring to element (" << row << ", " << col << "), but matrix size is " << mat.size() << "x" << mat[0].size();
    }
}

int Matrix::GetRows() const
{
     return mat.size();
}

int Matrix::GetCols() const
{
   return mat[0].size();
}

bool Matrix::operator==(const Matrix& m2)
{
    if (mat.size() == m2.GetRows() && mat[0].size() == m2.GetCols())
    {
    	for (int i = 0; i < mat.size() - 1; i++)
    	{
    		for (int j = 0; j < mat[0].size() - 1; j++)
    		{
    			if (mat[i][j] != m2.At(i, j))
    			{
    				return false;
    			}
    		}
    	}
    	return true;
    }
    else {
    	return false;
    }
}

bool Matrix::operator!=(const Matrix& m2)
{
    if (mat.size() == m2.GetRows() && mat[0].size() == m2.GetCols())
    {
    	for (int i = 0; i < mat.size() - 1; i++)
    	{
    		for (int j = 0; j < mat[0].size() - 1; j++)
    		{
    			if (mat[i][j] != m2.At(i, j))
    			{
    				return true;
    			}
    		}
    	}
    	return false;
    }
    else {
    	return true;
    }
}

Matrix Matrix::operator+(const Matrix& m2)
{
    try
    {
    	if (mat.size() != m2.GetRows() || mat[0].size() != m2.GetCols())
    	{
    		throw 1;
    	}
    	else
    	{
    		Matrix mres(m2.GetRows(), m2.GetCols());
    		for (int i = 0; i < mres.mat.size() - 1; i++)
    		{
    			for (int j = 0; j < mres.mat[0].size() - 1; j++)
    			{
    				mres.At(i, j) = mat[i][j] + m2.At(i, j);
    			}
    		}
    		return mres;
    	}
    }
    catch (int e)
    {
    	cout << "Can't sum matricies of different sizes";
    }
}
