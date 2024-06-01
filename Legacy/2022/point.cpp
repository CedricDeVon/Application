
#include <iostream>

#include "./point.h"

using namespace std;

point::point()
{
	_x = 0;
	_y = 0;
}

point::point(double x)
{
	_x = x;
	_y = 0;
}

point::point(double x, double y)
{
	_x = x;
	_y = y;
}

double point::getX()
{
	return _x;
}

double point::getY()
{
	return _y;
}

void point::setX(double x)
{
	_x = x;
}

void point::setY(double y)
{
	_y = y;
}

void point::draw()
{
	cout << '(' << _x << ", " << _y << ')' << '\n';
}

point::~point()
{
	
}