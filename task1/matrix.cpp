#include "matrix.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

Matrix::Matrix(int numRows, int numCols)
{
	//вывод ошибок
	if (rows < 0 || cols < 0)
	{
		throw out_of_range("");
    	}

	//при нуле строк или столбцев, или всё вместе
	if (numRows == 0 || numCols == 0)
	{
		rows = 0;
		cols = 0;
		mat.clear();
	} 
	//полноценное создание класса
	else
	{
		rows = numRows;
		cols = numCols;
		mat.assign(rows, vector<int>(cols,0));
	}
}

void Matrix::Reset(int numRows, int numCols)
{
    //вывод ошибок
	if (rows < 0 || cols < 0)
	{
		throw out_of_range("");
    	}

	//при нуле строк или столбцев, или всё вместе
	if (numRows == 0 || numCols == 0)
	{
		rows = 0;
		cols = 0;
		mat.clear();
	} 
	//полноценное создание класса
	else
	{
		rows = numRows;
		cols = numCols;
		mat.assign(rows, vector<int>(cols,0));
	}
}



int Matrix::At(int row, int col) const
{
    //вывод ошибок
	if (row < 0 || row >= num_rows || col < 0 || col >= num_cols)
	{
		throw out_of_range("");
    	}
    	return mat[row][col];
}

int& Matrix::At(int row, int col)
{
    //вывод ошибок
	if (row < 0 || row >= num_rows || col < 0 || col >= num_cols)
	{
		throw out_of_range("");
    	}
    	return mat[row][col];
    
}



int Matrix::GetRows() const
{
     return rows;
}

int Matrix::GetCols() const
{
   return cols;
}



bool operator==(const Matrix& lhs, const Matrix& rhs)
{
   	 return lhs.rows == rhs.rows && lhs.cols == rhs.cols && lhs.mat == rhs.mat;
}

bool operator!=(const Matrix& lhs, const Matrix& rhs)
{
    	return !(lhs == rhs);
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs.GetRows() != rhs.GetRows() || lhs.GetCols() != rhs.GetCols()) 
	{
        	cerr<<"невозможный аргумент";
    	}
    	Matrix result(lhs.GetRows(), lhs.GetCols());
    	for (int i = 0; i < lhs.GetRows(); ++i) 
		{
        		for (int j = 0; j < lhs.GetCols(); ++j) 
			{
            			result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        		}
    		}
    	return result;
}
