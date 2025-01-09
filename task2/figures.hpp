#pragma once

#include <memory>
#include <stdexcept>
#include <cmath>

enum class FigureType
{
    TRIANGLE,
    CIRCLE,
    RECTANGLE,
};

class Figure {
public:
    virtual ~Figure() = default;

    virtual FigureType Type() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Rect : public Figure
{
public:
    Rect(double width, double height);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double width_;
    double height_;
};

class Triangle : public Figure
{
public:
    Triangle(double a, double b, double c);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double a_;
    double b_;
    double c_;
};

class Circle : public Figure
{
public:
    Circle(double radius);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double radius_;
};

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);

class WrongTriangle : public std::invalid_argument
{
public:
    WrongTriangle();
};

class LessThanZeroParam : public std::invalid_argument
{
public:
    LessThanZeroParam();
};
