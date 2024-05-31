#include <iostream>
#include <vector>
#include "./point.h"
#include "./line.h"
#include "./polygon.h"

using namespace std;

polygon::polygon()
{

}

polygon::polygon(vector<point> &newPoints)
{
	_points = newPoints;
}

polygon::~polygon()
{

}

vector<point> polygon::getPoints()
{
	vector<point> copy;
	for (point currentPoint : _points)
	{
		copy.push_back(currentPoint);
	}
	return copy;
}

void polygon::addPoint(point p)
{
	_points.push_back(p);
}

double polygon::getPerimeter()
{
	vector<line> lines;
	lines.push_back(line(_points[0], _points[1]));
	lines.push_back(line(_points[_points.size() - 1], _points[0]));
	for (unsigned int currentIndex = 1; currentIndex < _points.size() - 1; currentIndex += 1)
	{
		lines.push_back(line(_points[currentIndex], _points[currentIndex + 1]));
	}

	double perimeterValue = 0;
	for (line currentLine : lines)
	{
		perimeterValue += currentLine.distance();
	}
	return perimeterValue;
}
