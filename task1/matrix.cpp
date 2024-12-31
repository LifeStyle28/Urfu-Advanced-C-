#include "matrix.hpp"
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix(int rows, int cols);
    void Reset(int rows, int cols);
    int& At(int row, int col);
    const int& At(int row, int col) const;
    int GetRows() const;
    int GetCols() const;
    
    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
    friend bool operator!=(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
    
private:
    int num_rows;
    int num_cols;
    vector<vector<int>> data;
};

Matrix::Matrix(int rows, int cols) {
    if (rows < 0 || cols < 0) {
        throw out_of_range("Rows and columns must be non-negative");
    }
    if (rows == 0 || cols == 0) {
        num_rows = 0;
        num_cols = 0;
        data.clear();
    } else {
        num_rows = rows;
        num_cols = cols;
        data.assign(rows, vector<int>(cols, 0));
    }
}

void Matrix::Reset(int rows, int cols) {
    if (rows < 0 || cols < 0) {
        throw out_of_range("Rows and columns must be non-negative");
    }
    if (rows == 0 || cols == 0) {
        num_rows = 0;
        num_cols = 0;
        data.clear();
    } else {
        num_rows = rows;
        num_cols = cols;
        data.assign(rows, vector<int>(cols, 0));
    }
}

int Matrix::At(int row, int col) const {
    if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
        throw out_of_range("Index out of range");
    }
    return data[row][col];
}

int& Matrix::At(int row, int col) {
    if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
        throw out_of_range("Index out of range");
    }
    return data[row][col];
}

int Matrix::GetRows() const {
    return num_rows;
}

int Matrix::GetCols() const {
    return num_cols;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    return lhs.num_rows == rhs.num_rows && lhs.num_cols == rhs.num_cols && lhs.data == rhs.data;
}

bool operator!=(const Matrix& lhs, const Matrix& rhs) {
    return !(lhs == rhs);
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetRows() != rhs.GetRows() || lhs.GetCols() != rhs.GetCols()) {
        throw invalid_argument("Matrices must have the same dimensions for addition");
    }
    Matrix result(lhs.GetRows(), lhs.GetCols());
    for (int i = 0; i < lhs.GetRows(); ++i) {
        for (int j = 0; j < lhs.GetCols(); ++j) {
            result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }
    return result;
}
