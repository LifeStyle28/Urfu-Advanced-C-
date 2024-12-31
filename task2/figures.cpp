#include "figures.hpp"
#include <cmath>

constexpr double PI = 3.14;

Rect::Rect(double a, double b) : width(a), height(b) {
    if (a < 0 || b < 0) {
        throw LessThanZeroParam("Dimensions cannot be negative");
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

Triangle::Triangle(double side_a, double side_b, double side_c) 
    : a(side_a), b(side_b), c(side_c) {
    if (side_a < 0 || side_b < 0 || side_c < 0) {
        throw LessThanZeroParam("Sides cannot be negative");
    }
    if (side_a + side_b <= side_c || side_b + side_c <= side_a || side_a + side_c <= side_b) {
        throw WrongTriangle("Invalid triangle sides");
    }
}

FigureType Triangle::Type() const {
    return FigureType::TRIANGLE;
}

double Triangle::Perimeter() const {
    return a + b + c;
}

double Triangle::Area() const {
    double s = Perimeter() / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

Circle::Circle(double r) : radius(r) {
    if (r < 0) {
        throw LessThanZeroParam("Radius cannot be negative");
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

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) {
    if (a < 0 || b < 0 || c < 0) {
        throw LessThanZeroParam("Parameters must be non-negative");
    }

    switch (type) {
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(a, b);

        case FigureType::TRIANGLE:
            if (a + b <= c || b + c <= a || a + c <= b) {
                throw WrongTriangle("Invalid triangle sides");
            }
            return std::make_unique<Triangle>(a, b, c);

        case FigureType::CIRCLE:
            return std::make_unique<Circle>(a);

        default:
            throw std::invalid_argument("Unknown figure type");
    }
}
