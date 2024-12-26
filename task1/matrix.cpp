#include "matrix.hpp"
#include <iostream>

#include <stdexcept>
Matrix::Matrix(int rowCount, int colCount) 
    : m_rows(rowCount), m_cols(colCount) {
    AllocateMemory();
}

Matrix::~Matrix() { 
    DeallocateMemory();
}

void Matrix::Reset(int rowCount, int colCount) {
    DeallocateMemory();  // Освобождаем старую память

    if (rowCount <= 0 || colCount <= 0) {
        m_rows = 0;
        m_cols = 0;
    } else {
        m_rows = rowCount;
        m_cols = colCount;
        AllocateMemory();
    }
}

int& Matrix::At(int row, int col) {
    CheckBounds(row, col);
    return elements[row][col];
}

Matrix::Matrix(int numRows, int numCols)
{
    // your implementation here
const int& Matrix::At(int row, int col) const {
    CheckBounds(row, col);
    return elements[row][col];
}

void Matrix::Reset(int numRows, int numCols)
{
    // your implementation here
int Matrix::GetRows() const {
    return m_rows;
}

int& Matrix::At(int row, int col)
{
    // your implementation here
int Matrix::GetCols() const {
    return m_cols;
}

const int& Matrix::At(int row, int col) const
{
    // your implementation here
bool Matrix::operator==(const Matrix& otherMatrix) const {
    if (m_rows != otherMatrix.m_rows || m_cols != otherMatrix.m_cols) return false;
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            if (elements[i][j] != otherMatrix.elements[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int Matrix::GetRows() const
{
    // your implementation here
bool Matrix::operator!=(const Matrix& otherMatrix) const {
    return !(*this == otherMatrix);
}

int Matrix::GetCols() const
{
    // your implementation here
Matrix Matrix::operator+(const Matrix& otherMatrix) const {
    if (m_rows != otherMatrix.m_rows || m_cols != otherMatrix.m_cols) {
        throw std::invalid_argument("Matrices dimensions do not match");
    }

    Matrix sumMatrix(m_rows, m_cols);
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            sumMatrix.At(i, j) = this->At(i, j) + otherMatrix.At(i, j);
        }
    }
    return sumMatrix;
}

bool Matrix::operator==(const Matrix& m2)
{
    // your implementation here
void Matrix::AllocateMemory() {
    if (m_rows > 0 && m_cols > 0) {
        elements = new int*[m_rows]; // Выделяем память для массива
        for (int i = 0; i < m_rows; ++i) {
            elements[i] = new int[m_cols]{0};  // Инициализация нулями
        }
    } else {
        elements = nullptr; // Указываем на nullptr, если размеры некорректны
    }
}

bool Matrix::operator!=(const Matrix& m2)
{
    // your implementation here
void Matrix::DeallocateMemory() {
    if (elements) {
        for (int i = 0; i < m_rows; ++i) {
            delete[] elements[i]; // Освобождаем каждый из массивов
        }
        delete[] elements; // Освобождаем массив
        elements = nullptr; // Устанавливаем указатель в nullptr для безопасности
    }
}

Matrix Matrix::operator+(const Matrix& m2)
{
    // your implementation here
void Matrix::CheckBounds(int row, int col) const {
    if (row < 0 || row >= m_rows || col < 0 || col >= m_cols) {
        throw std::out_of_range("Index out of range");
    }
}
