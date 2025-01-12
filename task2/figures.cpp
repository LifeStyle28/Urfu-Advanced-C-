#include "figures.hpp"
#include <cmath>
#include <stdexcept>


Rect::Rect(double length, double height) : length_(length), height_(height) {}

FigureType Rect::Type() const {
    return FigureType::RECTANGLE;
}

double Rect::Perimeter() const {
    return 2 * (length_ + height_);
}

double Rect::Area() const {
    return length_ * height_;
}

WrongTriangle::WrongTriangle(const std::string& message) : std::invalid_argument(message) {}

Triangle::Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {
    if (a_ + b_ <= c_ || a_ + c_ <= b_ || b_ + c_ <= a_) {
        throw WrongTriangle("Invalid triangle sides");
    }
}

FigureType Triangle::Type() const {
    return FigureType::TRIANGLE;
}

double Triangle::Perimeter() const {
    return a_ + b_ + c_;
}
 
double Triangle::Area() const {
    double s = Perimeter() / 2;
    return std::sqrt(s * (s - a_) * (s - b_) * (s - c_));
}

Circle::Circle(double radius) : radius_(radius) {}

FigureType Circle::Type() const {
    return FigureType::CIRCLE;
}

double Circle::Perimeter() const {
    return 2 * 3.14 * radius_;
}

double Circle::Area() const {
    return 3.14 * radius_ * radius_;
}

LessThanZeroParam::LessThanZeroParam(const std::string& message) : std::invalid_argument(message) {}

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) {
    if (a < 0 || b < 0 || c < 0) {
        throw LessThanZeroParam("Negative parameter value");
    }

    switch (type) {
    case FigureType::RECTANGLE:
        return std::make_unique<Rect>(a, b);
    case FigureType::CIRCLE:
        return std::make_unique<Circle>(a);
    case FigureType::TRIANGLE:
        return std::make_unique<Triangle>(a, b, c);
    default:
        throw std::invalid_argument("Unknown figure type");
    }
}

