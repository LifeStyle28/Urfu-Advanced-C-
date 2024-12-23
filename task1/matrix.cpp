#include "matrix.hpp"
#include <stdexcept>
#include <vector>

Matrix::Matrix() : numRows(0), numCols(0) {}

Matrix::Matrix(int numRows, int numCols) {
    Reset(numRows, numCols);
}


void Matrix::Reset(int numRows, int numCols) {
    if (numRows < 0 || numCols < 0) {
        throw std::invalid_argument("Number of rows and cols must be non-negative");
    }
    if (numRows == 0 || numCols == 0) {
        this->numRows = 0;
        this->numCols = 0;
        data.clear();
    }else {
        this->numRows = numRows;
        this->numCols = numCols;
        data.assign(numRows * numCols, 0);
    }
    
}

int& Matrix::At(int row, int col) {
    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row * numCols + col];
}

const int& Matrix::At(int row, int col) const {
    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row * numCols + col];
}

int Matrix::GetRows() const {
    return numRows;
}

int Matrix::GetCols() const {
    return numCols;
}

bool Matrix::operator==(const Matrix& m2) const {
     if (numRows != m2.numRows || numCols != m2.numCols) {
        return false;
    }
    for(int i=0; i < numRows * numCols; ++i) {
        if (data[i] != m2.data[i]) {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& m2) const {
    return !(*this == m2);
}

Matrix Matrix::operator+(const Matrix& m2) const {
    if (numRows != m2.numRows || numCols != m2.numCols) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }
    Matrix result(numRows, numCols);
    for(int i=0; i < numRows * numCols; ++i){
        result.data[i] = data[i] + m2.data[i];
    }
    return result;
}
