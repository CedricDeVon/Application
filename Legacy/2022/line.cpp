#include <cmath>

#include "./point.h"
#include "./line.h"

using namespace std;

void line::setStartPt(double x, double y)
{
	_startPt.setX(x);
	_startPt.setY(y);
}

void line::setEndPt(double x, double y)
{
	_endPt.setX(x); 
	_endPt.setY(y);
}

point line::getStartPt()
{
	return _startPt;
}

point line::getEndPt()
{
	return _endPt;
}

double line::distance()
{
	return sqrt(
		pow(_endPt.getX() - _startPt.getX(), 2) +
		pow(_endPt.getY() - _startPt.getY(), 2)
		);
}

double line::angle()
{
	return atan(
		(_endPt.getY() - _startPt.getY()) /
		(_endPt.getX() - _startPt.getX())
		) * 57.2958;
}

line::line(point a, point b)
{
	_startPt = a;
	_endPt = b;
}

line::~line()
{

}


