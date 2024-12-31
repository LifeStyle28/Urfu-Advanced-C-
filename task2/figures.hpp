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
    public:
        Rect(double a, double b);
        double Perimeter() const override;
        double Area()const override;
        FigureType Type() const override;
    private:
        double a, b;

};

class Triangle : public Figure
{
public:
    Triangle(double a, double b, double c);
    double Perimeter() const override;
    double Area()const override;
    FigureType Type() const override;
private:
    double a, b, c;
};

class Circle : public Figure
{
public:
    Circle(int r);
    double Perimeter() const override;
    double Area()const override;
    FigureType Type() const override;
private:
    int R;
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

