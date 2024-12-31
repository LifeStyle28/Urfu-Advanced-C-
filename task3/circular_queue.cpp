#include "circular_queue.hpp"
#include <vector>


//LET'S GOOOOOOOOOO, ЗАПОЛНИМ ЭТО КОЛЕЧКО *аранайка moment*
bool CircularQueue::Push(int value) 
{
   if (Full()) 
   {
      return false;
   }
   buffer[zad] = value;
   zad = (zad + 1) % max_razmer;
   now_rozmer++;
   return true;
}


//Это не просто смело, это грустно, НАШИ РЯДЫ РЕДЕЮТ!!!!!!! (╯°□°)╯︵ ┻━┻
bool CircularQueue::Pop() 
{
   if (Empty()) 
   {
      return false;
   }
   pered = (pered + 1) % max_razmer;
   now_rozmer--;
   return true;
}



//НАЙДИТЕ ПЕРВОЙ ЧИСЛО!!!! НАЙДИТЕ РОДИТЕЛЕЙ ПЕРВОГО ЧИСЛА, ПЕРЕВЕРНИТЕ ВСЁ ВЕРХ ДНОМ, НО НАЙДИТЕ ЕГО!!!!!!!!!!!!!!! 	୧((#Φ益Φ#))୨
int CircularQueue::Front() const 
{
   if (Empty()) 
   {
      return -1;
   }
   return buffer[pered];
}



//НАЙДИТЕ ПОСЛЕДНЕЕ ЧИСЛО!!! Но в этот рас спокойней (ᓀ‿ᓀ)
int CircularQueue::Back() const 
{
   if (Empty()) 
   {
      return -1;
   }
   return buffer[(zad - 1 + max_razmer) % max_razmer];
}



//Ля, Михалыч, очеред пуста, мы рАзОрИмСя!!!АААААА, у меня 5 детей, что мне делать, МиХаЛыЧ??? .･ﾟﾟ･(／ Ｏ＼)･ﾟﾟ･.
bool CircularQueue::Empty() const 
{
   return now_rozmer == 0;
}



//Кружка, что full of beer -> это счастье, monami 	( ￣▽￣)[] [](≧▽≦ )
bool CircularQueue::Full() const 
{
   return now_rozmer == max_razmer;
}

