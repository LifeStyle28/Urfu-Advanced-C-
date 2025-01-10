#include "figures.hpp"
#include <memory>
#include <stdexcept>
using namespace std;
static constexpr double PI = 3.14;

class Rect : public Figure
{
public:
    Rect(double l, double h)
    {
        this->l = l;
        this->h = h;
        if (l < 0 || h < 0) 
        {
            throw LessThanZeroParam("");
        }
    }
    FigureType Type() const
    {
        return FigureType::RECTANGLE;
    }
    double Perimeter() const
    {
        return 2*h+l*2
    }
    double Area() const
    {
        return h * l;
    }
};

class Triangle : public Figure
{
public:
    Triangle(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        if (a < 0 || b < 0 || c < 0) 
        {
            throw LessThanZeroParam("");
        }
        if (a + b <= c || a + c <= b || b + c <= a) 
        {
            throw WrongTriangle("");
        }
    }
    FigureType Type() const
    {
        return FigureType::TRIANGLE;
    }
    double Perimeter() const
    {
        return a + b + c;
    }
    double Area() const
    {
        double p = Perimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Circle : public Figure
{
public:
    Circle(double r)
    {
        this->r = r;
        if (r < 0) 
        {
            throw LessThanZeroParam("");
        }
    }
    FigureType Type() const
    {
        return FigureType::CIRCLE;
    }
    double Perimeter() const
    {
        return 2 * PI * r;
    }
    double Area() const
    {
        return PI * r * r;
    }
};

unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c)
{
    if (a < 0 || b < 0 || c < 0) 
    {
        throw LessThanZeroParam("");
    }
    if (type == FigureType::RECTANGLE) 
    {
        return make_unique<Rect>(a, b);
    }
    else if (type == FigureType::CIRCLE) 
    {
        return make_unique<Circle>(a);
    }
    else if (type == FigureType::TRIANGLE) 
    {
        if (a + b <= c || a + c <= b || b + c <= a) 
        {
            throw WrongTriangle("");
        }
        return make_unique<Triangle>(a, b, c);
    }
    else 
    {
        return nullptr;
    }
}
