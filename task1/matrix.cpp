cpp
#include <stdexcept>

class Matrix {
public:
    Matrix() = default;
    Matrix(int numRows, int numCols) : rows_(numRows), cols_(numCols), data_(numRows * numCols, 0) {}

    void Reset(int numRows, int numCols) {
        if (numRows <= 0 || numCols <= 0) {
            rows_ = cols_ = 0;
            data_.clear();
            return;
        }
        rows_ = numRows;
        cols_ = numCols;
        data_.resize(numRows * numCols);
    }
    int&amp; At(int row, int col) {
        if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
            throw std::out_of_range("Matrix index out of range");
        }
        return data_[row * cols_ + col];
    }
    const int&amp; At(int row, int col) const {
        if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
            throw std::out_of_range("Matrix index out of range");
        }
        return data_[row * cols_ + col];
    }
    int GetRows() const { return rows_; }
    int GetCols() const { return cols_; }

    bool operator==(const Matrix&amp; m2) {
        if (rows_ != m2.rows_ || cols_ != m2.cols_) {
            return false;
        }
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (At(i, j) != m2.At(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator!=(const Matrix&amp; m2) { return !(*this == m2); }
    Matrix operator+(const Matrix&amp; m2) {
        if (rows_ != m2.rows_ || cols_ != m2.cols_) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        Matrix result(rows_, cols_);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                result.At(i, j) = At(i, j) + m2.At(i, j);
            }
        }
        return result;
    }

private:
    int rows_ = 0;
    int cols_ = 0;
    std::vector<int> data_;
};
