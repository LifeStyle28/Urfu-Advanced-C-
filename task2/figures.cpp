#include "figures.hpp"
#include <cmath>



//Прямоугольник
FigureType Rect::Type() const 
{
   return FigureType::RECTANGLE;
}
double Rect::Perimeter() const 
{
   return 2 * (len + hei);
}
double Rect::Area() const 
{
   return len * hei;
}



//Треугольник
FigureType Triangle::Type() const 
{
   return FigureType::TRIANGLE;
}
double Triangle::Perimeter() const 
{
   return a + b + c;
}
double Triangle::Area() const 
{
   double s = Perimeter() / 2;
   return std::sqrt(s * (s - a) * (s - b) * (s - c));
}



//Круг
FigureType Circle::Type() const 
{
   return FigureType::CIRCLE;
}
double Circle::Perimeter() const 
{
   return 2 * PI * radius;
}
double Circle::Area() const 
{
   return PI * radius * radius;
}




//Universal konsruktor dla universalnosti
std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) 
{
   //при ноляках
   if (a < 0 || b < 0 || c < 0) 
   {
      throw LessThanZeroParam("");
   }
   //юниверсал фигура стала широким кавдратом (или узким ╮(￣ω￣;)╭)
   if (type == FigureType::RECTANGLE) 
   {
      return std::make_unique<Rect>(a, b);
   }
   //triangolo universale, mama mia ☆ ～('▽^人)
   if (type == FigureType::TRIANGLE) 
   {
      if (a + b <= c || b + c <= a || a + c <= b) 
      {
         throw WrongTriangle("");
      }
      return std::make_unique<Triangle>(a, b, c);
   }
   // К    Р    У    Г
   if (type == FigureType::CIRCLE) 
   {
      return std::make_unique<Circle>(a);
   }

   return nullptr;
}

int main()
{
   return 0;
}
