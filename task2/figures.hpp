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
   double PI = 3.14;
};



//Прямоугольник
class Rect : public Figure
{
private:
   double len;
   double hei;

public:
   Rect(double a, double b) : len(a), hei(b) {}
   FigureType Type() const override;
   double Perimeter() const override;
   double Area() const override;
};



//Треугольник
class Triangle : public Figure
{
private:
   double a, b, c;

public:
   Triangle(double side_a, double side_b, double side_c) : a(side_a), b(side_b), c(side_c) {}
   FigureType Type() const override;
   double Perimeter() const override;
   double Area() const override;
};



//Круг
class Circle : public Figure
{
private:
   double radius;

public:
   Circle(double r) : radius(r) {}
   FigureType Type() const override;
   double Perimeter() const override;
   double Area() const override;
};



//Конструктор (лего)
std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);



//Исключение special for treugolnk
class WrongTriangle : public std::invalid_argument
{
public:
   using std::invalid_argument::invalid_argument;
}; 



//Для дебилов с отрицательными фигурами
class LessThanZeroParam : public std::invalid_argument
{
public:
   using std::invalid_argument::invalid_argument;
};
