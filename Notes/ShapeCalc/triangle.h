#pragma once
#include <iostream>
#include <cmath>
#include "shape.h"

using namespace std;

class Triangle : public Shape
{
    private:
    float _side1;
    float _side2;
    float _side3;
    float _area;
    float _perimeter;
    
    
    public:
    Triangle(float = 0, float = 0, float = 0);
    void calculatearea();
    void calculateperimeter();
    void printvalues();

};

 Triangle::Triangle(float side1, float side2, float side3)
 {
    _side1 = side1;
    _side2 = side2;
    _side3 = side3;
    _area = 0;
    _perimeter = 0;
 }
void Triangle::calculatearea()
{
    float s = (_side1 + _side2 + _side3) / 2;
    _area = sqrt(s * (s - _side1) * (s - _side2) * (s - _side3));
}

void Triangle::calculateperimeter()
{
    _perimeter = _side1 + _side2 + _side3;
}

void Triangle::printvalues()
{
    std::cout << "Side 1 of triangle: " << _side1 << std::endl;
    std::cout << "Side 2 of triangle: " << _side2 << std::endl;
    std::cout << "Side 3 of triangle: " << _side3 << std::endl;
    std::cout << "Area of triangle: " << _area << std::endl;
    std::cout << "Perimeter of triangle: " << _perimeter << std::endl;
}
