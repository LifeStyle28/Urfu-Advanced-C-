#pragma once

#include <memory>
#include <stdexcept>
#include <cmath> // для M_PI

// Используем стандартную константу для числа π
#ifndef M_PI
static constexpr double PI = 3.14159265358979323846;
#else
static constexpr double PI = M_PI;
#endif

// Тип фигуры
enum class FigureType {
    TRIANGLE,
    CIRCLE,
    RECTANGLE,
};

// Базовый класс для всех фигур
class Figure {
public:
    virtual FigureType Type() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
    virtual ~Figure() = default;
};

// Прямоугольник
class Rect : public Figure {
public:
    Rect(double width, double height);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double width;
    double height;
};

// Треугольник
class Triangle : public Figure {
public:
    Triangle(double a, double b, double c);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double a, b, c;
};

// Круг
class Circle : public Figure {
public:
    Circle(double radius);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double radius;
};

// Фабричная функция для создания фигур
std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);

// Исключение: неправильный треугольник
class WrongTriangle : public std::invalid_argument {
public:
    explicit WrongTriangle(const std::string& message) : std::invalid_argument(message) {}
};

// Исключение: параметры меньше нуля
class LessThanZeroParam : public std::invalid_argument {
public:
    explicit LessThanZeroParam(const std::string& message) : std::invalid_argument(message) {}
};
