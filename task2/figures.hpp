#pragma once

#include <memory>
#include <stdexcept>


constexpr double PI = 3.14;

enum class FigureType {
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

class Rect : public Figure {
private:
    double rect_width;
    double rect_height;

public:
    Rect(double width_val, double height_val);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
};

class Triangle : public Figure {
private:
    double side_a;
    double side_b;
    double side_c;

public:
    Triangle(double side1, double side2, double side3);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
};

class Circle : public Figure {
private:
    double circle_radius;

public:
    Circle(double radius_val);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
};

std::unique_ptr<Figure> make_figure(FigureType figure_type, double param1, double param2 = 0, double param3 = 0);

class WrongTriangle : public std::invalid_argument {
public:
    using std::invalid_argument::invalid_argument;
};

class LessThanZeroParam : public std::invalid_argument {
public:
    using std::invalid_argument::invalid_argument;
};
