#include <iostream>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <variant>

static constexpr double PI = 3.14159265358979323846;

enum class FigureType {
    RECTANGLE,
    TRIANGLE,
    CIRCLE
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
    double width;
    double height;

public:
    Rect(double w, double h) : width(w), height(h) {}

    FigureType Type() const override {
        return FigureType::RECTANGLE;
    }

    double Perimeter() const override {
        return 2 * (width + height);
    }

    double Area() const override {
        return width * height;
    }
};

class Triangle : public Figure {
private:
    double a, b, c;

public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {
        if (a <= 0 || b <= 0 || c <= 0) {
            throw std::invalid_argument("Sides must be positive.");
        }
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw std::invalid_argument("Invalid triangle sides.");
        }
    }

    FigureType Type() const override {
        return FigureType::TRIANGLE;
    }

    double Perimeter() const override {
        return a + b + c;
    }

    double Area() const override {
        double s = Perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive.");
        }
    }

    FigureType Type() const override {
        return FigureType::CIRCLE;
    }

    double Perimeter() const override {
        return 2 * PI * radius;
    }

    double Area() const override {
        return PI * radius * radius;
    }
};

using FigureVariant = std::variant<Rect, Triangle, Circle>;

FigureVariant make_figure(FigureType type, double a, double b = 0, double c = 0) {
    switch (type) {
        case FigureType::RECTANGLE:
            return Rect(a, b);
        case FigureType::CIRCLE:
            return Circle(a);
        case FigureType::TRIANGLE:
            return Triangle(a, b, c);
        default:
            throw std::invalid_argument("Unsupported figure type.");
    }
}

int main() {
    try {
        auto rect = std::get<Rect>(make_figure(FigureType::RECTANGLE, 5.0, 3.0));
        std::cout << "Rectangle Area: " << rect.Area() << ", Perimeter: " << rect.Perimeter() << std::endl;

        auto circle = std::get<Circle>(make_figure(FigureType::CIRCLE, 4.0));
        std::cout << "Circle Area: " << circle.Area() << ", Perimeter: " << circle.Perimeter() << std::endl;

        auto triangle = std::get<Triangle>(make_figure(FigureType::TRIANGLE, 3.0, 4.0, 5.0));
        std::cout << "Triangle Area: " << triangle.Area() << ", Perimeter: " << triangle.Perimeter() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
