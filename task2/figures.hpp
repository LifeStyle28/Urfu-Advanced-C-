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
    Rect(double height, double width);

    virtual FigureType Type() const override;
    virtual double Perimeter() const override;
    virtual double Area() const override;

private:
    double height_;
    double width_;
};

class Triangle : public Figure
{
public:
    Triangle(double a, double b, double c);

    static bool IsValidTriangle(double a, double b, double c);

    virtual FigureType Type() const override;
    virtual double Perimeter() const override;
    virtual double Area() const override;

private:
    double a_;
    double b_;
    double c_;
};

class Circle : public Figure
{
public:
    Circle(double radius);

    virtual FigureType Type() const override;
    virtual double Perimeter() const override;
    virtual double Area() const override;

private:
    double radius_;
};

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);

class WrongTriangle : public std::invalid_argument
{
public:
    WrongTriangle(std::string msg);
};

class LessThanZeroParam : public std::invalid_argument
{
public:
    LessThanZeroParam(std::string msg);
};
