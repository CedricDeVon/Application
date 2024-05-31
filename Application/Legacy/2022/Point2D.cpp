#include <iostream>

#include "./Point2D.h"

using namespace std;

Point2D::Point2D(int x, int y) : Point1D(x)
{
	_y = y;
}

int Point2D::getY()
{
	return _y;
}

void Point2D::setY(int y)
{
	_y = y;
}

void Point2D::printCoordinates()
{
	cout << "(" << _x << ", " << _y << ")" << '\n';
}

Point2D::~Point2D()
{
	cout << "Done 2D!" << '\n';
}

