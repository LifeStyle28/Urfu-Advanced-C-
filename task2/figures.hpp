#pragma once

#include <memory>
#include <stdexcept>
#include <cmath>

enum class ShapeType {
    Triangle,
    Circle,
    Rectangle
};

class Shape {
public:
    virtual ~Shape() = default;

    virtual ShapeType GetType() const = 0;
    virtual double GetPerimeter() const = 0;
    virtual double GetArea() const = 0;
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height);
    ShapeType GetType() const override;
    double GetPerimeter() const override;
    double GetArea() const override;
};

class Triangle : public Shape {
private:
    double sideA, sideB, sideC;

public:
    Triangle(double a, double b, double c);
    ShapeType GetType() const override;
    double GetPerimeter() const override;
    double GetArea() const override;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius);
    ShapeType GetType() const override;
    double GetPerimeter() const override;
    double GetArea() const override;
};

std::unique_ptr<Shape> CreateShape(ShapeType type, double a, double b = 0, double c = 0);

class InvalidTriangleException : public std::invalid_argument {
public:
    InvalidTriangleException(const char* msg) : std::invalid_argument(msg) {}
};

class NegativeParameterException : public std::invalid_argument {
public:
    NegativeParameterException(const char* msg) : std::invalid_argument(msg) {}
};
