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



int Matrix::At(int row, int col)
{
    //вывод ошибок
	if (row < 0)
    	{
		cerr<<"Произошла ошибка -> нет строки меньше нуля, дебил, ты сто пытаешься найти? Я вот твою логику (◣_◢)";
    	}
   	if (col < 0)
	{
		cerr<<"Произошла ошибка -> нет столбца меньше нуля, никак вы б$@&* не научитесь (╬ಠ益ಠ)";
    	}
	if (row >= rows)
	{
		cerr<<"Произошла ошибка -> у нас строк меньше, дружок пирожок (─‿‿─)";
    	}
	if (col >= cols)
	{
		cerr<<"Произошла ошибка -> эээээм, у нас, ващет, столбцев меньше (￣︿￣)";
    	}
    	return mat[row][col];

int& Matrix::At(int row, int col) const
{
    //вывод ошибок
	if (row < 0)
    	{
		cerr<<"Произошла ошибка -> нет строки меньше нуля, дебил, ты сто пытаешься найти? Я вот твою логику (◣_◢)";
    	}
   	if (col < 0)
	{
		cerr<<"Произошла ошибка -> нет столбца меньше нуля, никак вы б$@&* не научитесь (╬ಠ益ಠ)";
    	}
	if (row >= rows)
	{
		cerr<<"Произошла ошибка -> у нас строк меньше, дружок пирожок (─‿‿─)";
    	}
	if (col >= cols)
	{
		cerr<<"Произошла ошибка -> эээээм, у нас, ващет, столбцев меньше (￣︿￣)";
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
    	else 
	{
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
	else 
	{
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
