#pragma once
#include <cmath>
#include <memory>
#include <stdexcept>
#include <numbers>
static constexpr double pi = 3.14;
enum class FigureType
{
    TRIANGLE,
    CIRCLE,
    RECTANGLE,
};

class Figure {
public:
    virtual FigureType Type() const = 0;
    virtual ~Figure() = default; 
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Rect : public Figure
{
private:
    double width;
    double height;
public:
    Rect(double width, double height);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
};

class Triangle : public Figure
{
private:
    double a, b, c;
public:
    Triangle(double a, double b, double c);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
};

class Circle : public Figure
{
public:
    Circle(double rad);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
private:
    double rad;
};

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);

class WrongTriangle : public std::invalid_argument
{
public:
    using std::invalid_argument::invalid_argument;
};

class LessThanZeroParam : public std::invalid_argument
{
public:
    using std::invalid_argument::invalid_argument;
};

