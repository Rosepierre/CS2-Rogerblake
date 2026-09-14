#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    _x = X;
    _y = Y;
    _nearestPoint = closestPoint;
}
//Destructor
points::Point::~Point()
{
    delete _nearestPoint;
}

//Getters
int points::Point::getX()
{
    return _x;
}

int points::Point::getY()
{
    return _y;
}

points::Point* points::Point::getNearestPoint()
{
    return _nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    if (arrSize > 0)
    {
        
    }
}

//Setters
void points::Point::setX(int newVal)
{
    _x = newVal;
}

void points::Point::setY(int newVal)
{
    _y = newVal;
\
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
    _nearestPoint = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{
    calcNearestPoint(nullptr, 0);
}