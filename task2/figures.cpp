#include "figures.hpp"

static constexpr double PI = 3.14;

// Rect implementation
Rect::Rect(double width, double height) : width_(width), height_(height)
{
    if (width < 0 || height < 0)
        throw LessThanZeroParam();
}

FigureType Rect::Type() const { return FigureType::RECTANGLE; }

double Rect::Perimeter() const { return 2 * (width_ + height_); }

double Rect::Area() const { return width_ * height_; }

// Triangle implementation
Triangle::Triangle(double a, double b, double c) : a_(a), b_(b), c_(c)
{
    if (a < 0 || b < 0 || c < 0)
        throw LessThanZeroParam();

    if (a + b <= c || a + c <= b || b + c <= a)
        throw WrongTriangle();
}

FigureType Triangle::Type() const { return FigureType::TRIANGLE; }

double Triangle::Perimeter() const { return a_ + b_ + c_; }

double Triangle::Area() const
{
    double s = Perimeter() / 2;
    return std::sqrt(s * (s - a_) * (s - b_) * (s - c_));
}

// Circle implementation
Circle::Circle(double radius) : radius_(radius)
{
    if (radius < 0)
        throw LessThanZeroParam();
}

FigureType Circle::Type() const { return FigureType::CIRCLE; }

double Circle::Perimeter() const { return 2 * PI * radius_; }

double Circle::Area() const { return PI * radius_ * radius_; }

// Custom exceptions
WrongTriangle::WrongTriangle() : std::invalid_argument("Invalid triangle sides") {}

LessThanZeroParam::LessThanZeroParam() : std::invalid_argument("Parameter cannot be less than zero") {}

// Factory function
std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c)
{
    switch (type)
    {
    case FigureType::RECTANGLE:
        return std::make_unique<Rect>(a, b);
    case FigureType::TRIANGLE:
        return std::make_unique<Triangle>(a, b, c);
    case FigureType::CIRCLE:
        return std::make_unique<Circle>(a);
    default:
        throw std::invalid_argument("Unknown figure type");
    }
}
