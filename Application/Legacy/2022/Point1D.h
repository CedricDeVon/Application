#pragma once

#include "./Point.h"

#ifndef Point1D_h
#define Point1D_h

class Point1D : public Point
{
public:
	Point1D(int);
	int getX();
	void setX(int);
	void printCoordinates();
	~Point1D();

protected:
	int _x = 0;
};

#endif