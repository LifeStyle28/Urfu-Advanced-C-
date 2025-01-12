#include "figures.hpp"
#include <cmath>
#include "matrix.hpp"
#include <stdexcept>

Rect::Rect(double w, double h) : width(w), height(h) {
    if (w < 0 || h < 0) {
        throw LessThanZeroParam();
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

FigureType Rect::Type() const {
    return FigureType::RECTANGLE;
}

double Rect::Perimeter() const {
    return (width + height) * 2;
}

double Rect::Area() const {
    return width * height;
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

Triangle::Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {
    if (side1 < 0 || side2 < 0 || side3 < 0) {
        throw LessThanZeroParam();
    }
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        throw WrongTriangle();
int Matrix::At(int r, int c) const {
    if (r < 0 || r >= num_rows || c < 0 || c >= num_cols) {
        throw std::out_of_range("");
    }
    return data[r][c];
}

FigureType Triangle::Type() const {
    return FigureType::TRIANGLE;
int& Matrix::At(int r, int c) {
    if (r < 0 || r >= num_rows || c < 0 || c >= num_cols) {
        throw std::out_of_range("");
    }
    return data[r][c];
}

double Triangle::Perimeter() const {
    return a + b + c;
int Matrix::GetRows() const {
    return num_rows;
}

double Triangle::Area() const {
    double half_perimeter = Perimeter() / 2;
    return std::sqrt(half_perimeter * (half_perimeter - a) * (half_perimeter - b) * (half_perimeter - c));
int Matrix::GetCols() const {
    return num_cols;
}

Circle::Circle(double r) : radius(r) {
    if (r < 0) {
        throw LessThanZeroParam();
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

FigureType Circle::Type() const {
    return FigureType::CIRCLE;
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

double Circle::Perimeter() const {
    return 2 * PI * radius;
bool operator==(const Matrix& m1, const Matrix& m2) {
    return m1.num_rows == m2.num_rows && m1.num_cols == m2.num_cols && m1.data == m2.data;
}

double Circle::Area() const {
    return PI * radius * radius;
bool operator!=(const Matrix& m1, const Matrix& m2) {
    return !(m1 == m2);
}

std::unique_ptr<Figure> make_figure(FigureType type, double x, double y, double z) {
    if (x < 0 || y < 0 || z < 0) {
        throw LessThanZeroParam();
Matrix operator+(const Matrix& m1, const Matrix& m2) {
    if (m1.GetRows() != m2.GetRows() || m1.GetCols() != m2.GetCols()) {
        throw std::invalid_argument("");
    }

    switch (type) {
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(x, y);
        case FigureType::CIRCLE:
            return std::make_unique<Circle>(x);
        case FigureType::TRIANGLE:
            return std::make_unique<Triangle>(x, y, z);
        default:
            return nullptr;
    Matrix res(m1.GetRows(), m1.GetCols());
    for (int i = 0; i < m1.GetRows(); ++i) {
        for (int j = 0; j < m1.GetCols(); ++j) {
            res.At(i, j) = m1.At(i, j) + m2.At(i, j);
        }
    }
    return res;
}

