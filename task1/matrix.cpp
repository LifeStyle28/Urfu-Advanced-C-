#include "matrix.hpp"

#include <stdexcept>


// Конструктор
Matrix::Matrix(int numRows, int numCols) {
    Reset(numRows, numCols);
}

// Сброс размеров матрицы
void Matrix::Reset(int numRows, int numCols) {
    if (numRows <= 0 || numCols <= 0) {
        data.clear(); // Очистка, если размеры некорректны.
        return;
    }
    data.resize(numRows, std::vector<int>(numCols, 0)); // Инициализируем матрицу нулями
}

// Доступ к элементу по индексу
int& Matrix::At(int row, int col) {
    if (row < 0 || row >= GetRows() || col < 0 || col >= GetCols()) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

const int& Matrix::At(int row, int col) const {
    if (row < 0 || row >= GetRows() || col < 0 || col >= GetCols()) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

// Получение количества строк
int Matrix::GetRows() const {
    return data.size();
}

// Получение количества столбцов
int Matrix::GetCols() const {
    return data.empty() ? 0 : data[0].size();
}

// Оператор сравнения на равенство
bool Matrix::operator==(const Matrix& m2) {
    if (GetRows() != m2.GetRows() || GetCols() != m2.GetCols()) {
        return false;
    }
    for (int i = 0; i < GetRows(); ++i) {
        for (int j = 0; j < GetCols(); ++j) {
            if (At(i, j) != m2.At(i, j)) {
                return false;
            }
        }
    }
    return true;
}

// Оператор сравнения на неравенство
bool Matrix::operator!=(const Matrix& m2) {
    return !(*this == m2);
}

// Оператор сложения матриц
Matrix Matrix::operator+(const Matrix& m2) {
    if (GetRows() != m2.GetRows() || GetCols() != m2.GetCols()) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }
    Matrix result(GetRows(), GetCols());
    for (int i = 0; i < GetRows(); ++i) {
        for (int j = 0; j < GetCols(); ++j) {
            result.At(i, j) = At(i, j) + m2.At(i, j);
        }
    }
    return result;
}
