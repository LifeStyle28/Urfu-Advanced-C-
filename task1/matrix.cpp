#include "matrix.hpp"
#include <stdexcept>

Matrix::Matrix(int r, int c) {
    if (r < 0 || c < 0) {
        throw std::out_of_range("");
    }
    if (r == 0 || c == 0) {
        num_rows = 0;
        num_cols = 0;
        data.clear();
    } else {
        num_rows = r;
        num_cols = c;
        data.assign(r, std::vector<int>(c, 0));
    }
}

void Matrix::Reset(int r, int c) {
    if (r < 0 || c < 0) {
        throw std::out_of_range("");
    }
    if (r == 0 || c == 0) {
        num_rows = 0;
        num_cols = 0;
        data.clear();
    } else {
        num_rows = r;
        num_cols = c;
        data.assign(r, std::vector<int>(c, 0));
    }
}

int Matrix::At(int r, int c) const {
    if (r < 0 || r >= num_rows || c < 0 || c >= num_cols) {
        throw std::out_of_range("");
    }
    return data[r][c];
}

int& Matrix::At(int r, int c) {
    if (r < 0 || r >= num_rows || c < 0 || c >= num_cols) {
        throw std::out_of_range("");
    }
    return data[r][c];
}

int Matrix::GetRows() const {
    return num_rows;
}

int Matrix::GetCols() const {
    return num_cols;
}

std::istream& operator>>(std::istream& in, Matrix& m) {
    int r, c;
    in >> r >> c;
    m.Reset(r, c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            in >> m.At(i, j);
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    out << m.GetRows() << " " << m.GetCols() << "\n";
    for (int i = 0; i < m.GetRows(); ++i) {
        for (int j = 0; j < m.GetCols(); ++j) {
            out << m.At(i, j) << " ";
        }
        out << "\n";
    }
    return out;
}

bool operator==(const Matrix& m1, const Matrix& m2) {
    return m1.num_rows == m2.num_rows && m1.num_cols == m2.num_cols && m1.data == m2.data;
}

bool operator!=(const Matrix& m1, const Matrix& m2) {
    return !(m1 == m2);
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    if (m1.GetRows() != m2.GetRows() || m1.GetCols() != m2.GetCols()) {
        throw std::invalid_argument("");
    }
    Matrix res(m1.GetRows(), m1.GetCols());
    for (int i = 0; i < m1.GetRows(); ++i) {
        for (int j = 0; j < m1.GetCols(); ++j) {
            res.At(i, j) = m1.At(i, j) + m2.At(i, j);
        }
    }
    return res;
}
