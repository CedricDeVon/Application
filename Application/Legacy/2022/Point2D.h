#pragma once

#include "./Point1D.h"

#ifndef Point2D_h
#define Point2D_h

class Point2D : public Point1D
{
public:
	Point2D(int, int);
	int getY();
	void setY(int);
	void printCoordinates();
	~Point2D();

protected:
	int _y = 0;
};

#endif