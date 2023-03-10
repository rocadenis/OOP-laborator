#include "Canvas.h"
#include <iostream>
#include <cstring>

int main()
{
    Canvas canvas(30, 20);
    //canvas.SetPoint(10,10, 'X');
    //canvas.DrawLine(0, 0, 29, 19, '*');
    //canvas.DrawCircle(15, 10, 8, '@');
    //canvas.FillCircle(25, 10, 5, '#');
    canvas.DrawRect(5, 5, 25, 15, '-');
    canvas.FillRect(7, 7, 23, 13, '+');
    canvas.Print();

    //std::cout << "Press Enter to clear the canvas.";
    //std::cin.get();

    canvas.Clear();
    //canvas.Print();

    return 0;
}
