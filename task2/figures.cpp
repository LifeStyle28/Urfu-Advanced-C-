#include "figures.hpp"

static constexpr double PI = 3.14;

#include <iostream>
#include <memory>
#include <stdexcept>
#include <cmath>

Rect::Rect(double a, double b) : width(a), height(b) 
{ 
    if (width < 0 || height < 0) {
            throw LessThanZeroParam("Width or height can't be less than zero.");
    }
}

FigureType Rect::Type() const {
    return FigureType::RECTANGLE;
}

double Rect::Perimeter() const {
    return 2 * (width + height);
}

double Rect::Area() const {
    return width * height;
}

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw LessThanZeroParam("Sides must be greater than zero.");
    }
    
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw WrongTriangle("Triangle does not exist.");
    }
}

FigureType Triangle::Type() const override {
    return FigureType::TRIANGLE;
}

double Triangle::Perimeter() const override {
    return a + b + c;
}

double Triangle::Area() const override {
    double p = Perimeter() / 2; 
    return std::sqrt(p * (p - a) * (p - b) * (p - c)); 
}


Circle::Circle(double a) : radius(a) {
    if (a < 0) {
        throw LessThanZeroParam("Radius must be non-negative.");
    }
}

FigureType Circle::Type() const override {
    return FigureType::CIRCLE;
}

double Circle::Perimeter() const override {
    return 2 * PI * radius; 
}

double Circle::Area() const override {
    return PI * radius * radius; 
}

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) {
    if (a < 0 || b < 0 || c < 0) {
        throw LessThanZeroParam("Sides must be greater than zero.");
    }
        
    switch (type) {
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
