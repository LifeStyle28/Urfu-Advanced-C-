#pragma once

#include <memory>
#include <stdexcept>
#include <string>

enum class FigureType {
    TRIANGLE,
    CIRCLE,
    RECTANGLE,
};

class Figure {
public:
    virtual FigureType Type() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
    virtual ~Figure() = default;
};

class Rect : public Figure {
public:
    Rect(double length, double height);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double length_;
    double height_;
};

class WrongTriangle : public std::invalid_argument {
public:
    WrongTriangle(const std::string& message);
};

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double a_, b_, c_;
};

class Circle : public Figure {
public:
    Circle(double radius);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double radius_;
};

class LessThanZeroParam : public std::invalid_argument {
public:
    LessThanZeroParam(const std::string& message);
};

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);

