#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

int main(int argc, char* argv[])
{
    Rectangle r1(42, 15);
    Circle c1(42);
    Triangle t1(3, 4, 5);

    r1.calculatearea();
    r1.calculateperimeter();

    c1.calculatearea();
    c1.calculateperimeter();

    t1.calculatearea();
    t1.calculateperimeter();

    r1.printvalues();
    c1.printvalues();
    t1.printvalues();

    return 0;

}