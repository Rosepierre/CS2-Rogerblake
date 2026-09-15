#pragma once
#include <iostream>
#include "shape.h"
using namespace std;

class Rectangle : public Shape
{
    private:
    int _side1;
    int _side2;
    int _area;
    int _perimeter;

    public:
    Rectangle(int = 0, int = 0);
    void calculatearea();
    void calculateperimeter();
    void printvalues();

};

 Rectangle::Rectangle(int side1, int side2)
 {
    _side1= side1;
    _side2= side2;
    _area = 0;
    _perimeter = 0;
 }
void Rectangle::calculatearea()
{
    _area = _side1 * _side2;
}

void Rectangle::calculateperimeter()
{
    _perimeter = 2 * (_side1 + _side2);
}


void Rectangle::printvalues()
{
    std::cout << "Side 1 of rectangle: " << _side1 << std::endl;
    std::cout << "Side 2 of rectangle: " << _side2 << std::endl;
    std::cout << "Area of rectangle: " << _area << std::endl;
    std::cout << "Perimeter of rectangle: " << _perimeter << std::endl;
}