#include "matrix.hpp"
#include <stdexcept>

using namespace std;

Matrix::Matrix(int height, int width) {
    if (height < 0 || width < 0) {
        throw out_of_range("");
    }
    if (height == 0 || width == 0) {
        row_count = 0;
        col_count = 0;
        data.clear();
    }
    else {
        row_count = height;
        col_count = width;
        data.assign(height, vector<int>(width, 0));
    }
}

void Matrix::Reset(int height, int width) {
    if (height < 0 || width < 0) {
        throw out_of_range("");
    }
    if (height == 0 || width == 0) {
        row_count = 0;
        col_count = 0;
        data.clear();
    }
    else {
        row_count = height;
        col_count = width;
        data.assign(height, vector<int>(width, 0));
    }
}

int Matrix::At(int row_idx, int col_idx) const {
    if (row_idx < 0 || row_idx >= row_count || col_idx < 0 || col_idx >= col_count) {
        throw out_of_range("");
    }
    return data[row_idx][col_idx];
}

int& Matrix::At(int row_idx, int col_idx) {
    if (row_idx < 0 || row_idx >= row_count || col_idx < 0 || col_idx >= col_count) {
        throw out_of_range("");
    }
    return data[row_idx][col_idx];
}

int Matrix::GetRows() const {
    return row_count;
}

int Matrix::GetCols() const {
    return col_count;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    return lhs.row_count == rhs.row_count && lhs.col_count == rhs.col_count && lhs.data == rhs.data;
}

bool operator!=(const Matrix& lhs, const Matrix& rhs) {
    return !(lhs == rhs);
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetRows() != rhs.GetRows() || lhs.GetCols() != rhs.GetCols()) {
        throw invalid_argument("");
    }
    Matrix result(lhs.GetRows(), lhs.GetCols());
    for (int row_idx = 0; row_idx < lhs.GetRows(); ++row_idx) {
        for (int col_idx = 0; col_idx < lhs.GetCols(); ++col_idx) {
            result.At(row_idx, col_idx) = lhs.At(row_idx, col_idx) + rhs.At(row_idx, col_idx);
        }
    }
    return result;
}
