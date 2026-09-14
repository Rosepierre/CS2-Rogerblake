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
        double minDistance = distPoints(*pointList[0]);
        Point* nearestPoint = pointList[0];

        for (unsigned long i = 1; i < arrSize; i++)
        {
            double currentDistance = distPoints(*pointList[i]);
            if (currentDistance < minDistance)
            {
                minDistance = currentDistance;
                nearestPoint = pointList[i];
            }
        }

        return nearestPoint;
    }

    return nullptr;
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
    double distancex = _x - point._x;
    double distancey = _y - point._y;
    return sqrt(distancex * distancex + distancey * distancey);
}