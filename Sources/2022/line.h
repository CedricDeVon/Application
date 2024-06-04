#include "./point.h"

#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

class line
{
public:
	line(point, point);
	line();
	~line();
	point getStartPt();
	point getEndPt();
	void setStartPt(double, double);
	void setEndPt(double, double);
	double distance();
	double angle();

private:
	point _startPt;
	point _endPt;
};

#endif