#pragma once
#include <iostream>
#include "shape.h"

class NewShape : public Shape
{
    public:
    void calculatearea();

};

void NewShape::calculatearea()
{
    _area = 42;
}