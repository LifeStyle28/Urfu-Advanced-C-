#include "figures.hpp"
#include <cmath>

Rect::Rect(double width_val, double height_val) : rect_width(width_val), rect_height(height_val) {}

FigureType Rect::Type() const {
    return FigureType::RECTANGLE;
}

double Rect::Perimeter() const {
    return 2 * (rect_width + rect_height);
}

double Rect::Area() const {
    return rect_width * rect_height;
}

Triangle::Triangle(double side1, double side2, double side3)
    : side_a(side1), side_b(side2), side_c(side3) {
}

FigureType Triangle::Type() const {
    return FigureType::TRIANGLE;
}

double Triangle::Perimeter() const {
    return side_a + side_b + side_c;
}

double Triangle::Area() const {
    double semi_perimeter = Perimeter() / 2;
    return std::sqrt(semi_perimeter * (semi_perimeter - side_a) * (semi_perimeter - side_b) * (semi_perimeter - side_c));
}

Circle::Circle(double radius_val) : circle_radius(radius_val) {}

FigureType Circle::Type() const {
    return FigureType::CIRCLE;
}

double Circle::Perimeter() const {
    return 2 * PI * circle_radius;
}

double Circle::Area() const {
    return PI * circle_radius * circle_radius;
}

std::unique_ptr<Figure> make_figure(FigureType figure_type, double param1, double param2, double param3) {
    if (param1 < 0 || param2 < 0 || param3 < 0) {
        throw LessThanZeroParam("Parameters must be non-negative");
    }

    switch (figure_type) {
    case FigureType::RECTANGLE:
        return std::make_unique<Rect>(param1, param2);

    case FigureType::TRIANGLE:
        if (param1 + param2 <= param3 || param2 + param3 <= param1 || param1 + param3 <= param2) {
            throw WrongTriangle("Invalid triangle side lengths");
        }
        return std::make_unique<Triangle>(param1, param2, param3);

    case FigureType::CIRCLE:
        return std::make_unique<Circle>(param1);

    default:
        return nullptr;
    }
}
