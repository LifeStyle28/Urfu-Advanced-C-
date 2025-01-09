#include "figures.hpp"
#include <cmath>
#include <stdexcept>

static constexpr double PI = 3.14;

// Rect implementation
Rect::Rect(double width, double height) : width(width), height(height) {
    if (width < 0 || height < 0) {
        throw LessThanZeroParam("Width and height must be non-negative.");
    }
}

FigureType Rect::Type() const {
    return FigureType::RECTANGLE;
}

double Rect::Perimeter() const {
    return 2 * (width + height);
}

double Rect::Area() const {
    return width * height;
}

// Triangle implementation
Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {
    if (a < 0 || b < 0 || c < 0) {
        throw LessThanZeroParam("Sides of the triangle must be non-negative.");
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw WrongTriangle("The sum of any two sides of a triangle must be greater than the third side.");
    }
}

FigureType Triangle::Type() const {
    return FigureType::TRIANGLE;
}

double Triangle::Perimeter() const {
    return a + b + c;
}

double Triangle::Area() const {
    double p = Perimeter() / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

// Circle implementation
Circle::Circle(double radius) : radius(radius) {
    if (radius < 0) {
        throw LessThanZeroParam("Radius must be non-negative.");
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

// Factory function
std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) {
    switch (type) {
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(a, b);
        case FigureType::CIRCLE:
            return std::make_unique<Circle>(a);
        case FigureType::TRIANGLE:
            return std::make_unique<Triangle>(a, b, c);
        default:
            throw std::invalid_argument("Unknown FigureType.");
    }
}
