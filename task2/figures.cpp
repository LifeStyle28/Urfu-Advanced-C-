#include "figures.hpp"
#include <cmath>
#include <stdexcept>

Rect::Rect(double w, double h) : width(w), height(h) {
    if (w < 0 || h < 0) {
        throw LessThanZeroParam();
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
} 

Triangle::Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {
    if (side1 < 0 || side2 < 0 || side3 < 0) {
        throw LessThanZeroParam();
    }
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        throw WrongTriangle();
    }
}

FigureType Triangle::Type() const {
    return FigureType::TRIANGLE;
}

double Triangle::Perimeter() const {
    return a + b + c;
}

double Triangle::Area() const {
    double half_perimeter = Perimeter() / 2;
    return std::sqrt(half_perimeter * (half_perimeter - a) * (half_perimeter - b) * (half_perimeter - c));
}

Circle::Circle(double r) : radius(r) {
    if (r < 0) {
        throw LessThanZeroParam();
    }
}

FigureType Circle::Type() const {
    return FigureType::CIRCLE;
}

double Circle::Perimeter() const {
    return 2 * PI * radius;
}

double Circle::Area() const {
    return PI * radius * radius;
}

std::unique_ptr<Figure> make_figure(FigureType type, double x, double y, double z) {
    if (x < 0 || y < 0 || z < 0) {
        throw LessThanZeroParam();
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
    }
}
