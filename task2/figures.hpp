#pragma once

#include <memory>
#include <stdexcept>

enum class FigureType
{
    TRIANGLE,
    CIRCLE,
    RECTANGLE,
};

class Figure {
public:
    virtual FigureType Type() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Rect : public Figure
{
private:
    double l,h;
public:
    Rect(double l, double h);
    FigureType Type() const;
    double Perimeter() const;
    double Area() const;
};

class Triangle : public Figure
{
private:
    double a,b,c;
public:
    Triangle(double a, double b, double c);
    FigureType Type() const;
    double Perimeter() const;
    double Area() const;
};

class Circle : public Figure
{
private:
    double r;
public:
    Circle(double r);
    FigureType Type() const;
    double Perimeter() const;
    double Area() const;
};

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);

class WrongTriangle : public invalid_argument 
{
public:
    WrongTriangle() : std::invalid_argument("") {}
};

class LessThanZeroParam : public invalid_argument 
{
public:
    LessThanZeroParam() : std::invalid_argument("") {}
};

