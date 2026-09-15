#pragma once
#include <iostream>
#include "shape.h"

using namespace std;

class Circle : public Shape
{
    private:
    float _radius;
    
    public:
    Circle(float = 0);
    void calculatearea();
    void calculateperimeter();
    void printvalues();

};

 Circle::Circle(float radius)
 {
    _radius= radius;
    _area = 0;
    _perimeter = 0;
    
 }
void Circle::calculatearea()
{
    _area = 3.14 * _radius * _radius;
}

void Circle::calculateperimeter()
{
    _perimeter = 2 * 3.14 * _radius;
}

void Circle::printvalues()
{
    std::cout << "Radius of circle: " << _radius << std::endl;
    std::cout << "Area of circle: " << _area << std::endl;
    std::cout << "Perimeter of circle: " << _perimeter << std::endl;
    
}
