#include <vector>
#include "./point.h"

using namespace std;

#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

class polygon
{
public:
	polygon(vector<point>&);
	polygon();
	~polygon();
	vector<point> getPoints();
	double getPerimeter();
	void addPoint(point);

private:
	vector<point> _points;
};

#endif