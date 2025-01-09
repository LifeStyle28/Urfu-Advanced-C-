#include "figures.hpp"

#include <cmath>
#include <stdexcept>

static constexpr double PI = 3.14;

Rect::Rect(double height, double width) : height_(height), width_(width) {
    if (height < 0 || width < 0) {
        throw LessThanZeroParam("Height and width must be non-negative.");
    }
}

FigureType Rect::Type() const {
    return FigureType::RECTANGLE;
}

double Rect::Perimeter() const {
    return 2 * (height_ + width_);
}

double Rect::Area() const {
    return height_ * width_;
}

// Triangle implementation
Triangle::Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {
    if (a < 0 || b < 0 || c < 0) {
        throw LessThanZeroParam("Sides must be non-negative.");
    }
    if (!IsValidTriangle(a, b, c)) {
        throw WrongTriangle("The provided sides do not form a valid triangle.");
    }
}

bool Triangle::IsValidTriangle(double a, double b, double c)
{
  return (a + b > c) && (a + c > b) && (b + c > a);
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

// Circle implementation
Circle::Circle(double radius) : radius_(radius) {
    if (radius < 0) {
        throw LessThanZeroParam("Radius must be non-negative.");
    }
}

FigureType Circle::Type() const {
    return FigureType::CIRCLE;
}

double Circle::Perimeter() const {
    return 2 * PI * radius_;
}

double Circle::Area() const {
    return PI * radius_ * radius_;
}

// Factory function to create figures
std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) {
    switch (type) {
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(a, b);
        case FigureType::TRIANGLE:
            return std::make_unique<Triangle>(a, b, c);
        case FigureType::CIRCLE:
            return std::make_unique<Circle>(a);
        default:
            throw std::invalid_argument("Unknown figure type.");
    }
}

WrongTriangle::WrongTriangle(std::string msg) :
    std::invalid_argument(msg)
{
}

LessThanZeroParam::LessThanZeroParam(std::string msg) :
    std::invalid_argument(msg)
{
}
