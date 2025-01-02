#include "figures.hpp"

static constexpr double PI = 3.14;
Rect::Rect(double width, double height) : width(width), height(height) {}

FigureType Rect::Type() const 
{
    return FigureType::RECTANGLE;
}

double Rect::Perimeter() const 
{
    return 2 * (width + height);
}

double Rect::Area() const 
{
    return width * height;
}


Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) 
{
    if (a <= 0 || b <= 0 || c <= 0) 
    {
        throw LessThanZeroParam(); 
    }
    if (a + b <= c || a + c <= b || b + c <= a) 
    {
        throw WrongTriangle(); 
    }
}

FigureType Triangle::Type() const 
{
    return FigureType::TRIANGLE;
}

double Triangle::Perimeter() const 
{
    return a + b + c;
}

double Triangle::Area() const 
{
    double s = Perimeter() / 2; 
    return sqrt(s * (s - a) * (s - b) * (s - c)); 
}


Circle::Circle(double radius) : radius(radius) 
{
    if (radius <= 0) 
    {
        throw LessThanZeroParam(); 
    }
}

FigureType Circle::Type() const 
{
    return FigureType::CIRCLE;
}

double Circle::Perimeter() const 
{
    return 2 * PI * radius;
}

double Circle::Area() const 
{
    return PI * radius * radius;
}

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) 
{
    switch (type) 
    {
        case FigureType::TRIANGLE:
            return std::make_unique<Triangle>(a, b, c);
        case FigureType::CIRCLE:
            return std::make_unique<Circle>(a);
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(a, b);
        default:
             return nullptr;
    }
}
