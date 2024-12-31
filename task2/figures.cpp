#include "figures.hpp"

static constexpr double PI = 3.14;
Triangle::Triangle(double a, double b, double c)
{
  if(a+b<=c || c+b<=a || a+c<=b)
  {
    throw WrongTriangle;
  }
}
double Triangle::Perimeter() const
{
    return a + b + c;
}

double Triangle::Area() const
{
    double p = 0.5 * Perimeter();
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

FigureType Triangle::Type() const
{
    return FigureType::TRIANGLE;
}


Circle::Circle(double r) : R(r) {}

double Circle::Perimeter() const
{
    return 2*PI*R;
}

double Circle::Area() const
{
    return PI*R*R;
}

FigureType Circle::Type() const
{
    return FigureType::CIRCLE;
}


Rect::Rect(double a, double b)
{
  
}

double Rect::Perimeter() const
{
    return 2*(a + b);
}

double Rect::Area() const
{
    return a*b;
}

FigureType Rect::Type() const
{
    return FigureType::RECTANGLE;
}


std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) 
{   if (a < 0 || b < 0 || c < 0) 
    {
        throw LessThanZeroParam;
    }
    switch (type) 
    {
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(a, b);
        case FigureType::CIRCLE:
            return std::make_unique<Circle>(a);
        case FigureType::TRIANGLE:
            return std::make_unique<Triangle>(a, b, c);
        default:
            return nullptr;
    }
}
