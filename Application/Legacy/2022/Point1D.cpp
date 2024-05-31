#include <iostream>

#include "./Point1D.h"

using namespace std;

Point1D::Point1D(int x)
{
	_x = x;
}

int Point1D::getX()
{
	return _x;
}

void Point1D::setX(int x)
{
	_x = x;
}

void Point1D::printCoordinates()
{
	cout << "(" << _x  << ")" << '\n';
}

Point1D::~Point1D()
{
	cout << "Done 1D!" << '\n';
}

