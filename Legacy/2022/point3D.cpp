#include <iostream>
#include "./point3D.h"

using namespace std;

point3D::point3D() : point(0, 0)
{
	_z = 0;
}

point3D::point3D(double x) : point(x, 0)
{
	_z = 0;
}

point3D::point3D(double x, double y) : point(x, y)
{
	_z = 0;
}

point3D::point3D(double x, double y, double z) : point(x, y)
{
	_z = z;
}

double point3D::getZ()
{
	return _z;
}

void point3D::setZ(double z)
{
	_z = z;
}

void point3D::draw()
{
	cout << '(' << _x << ", " << _y << ", " << _z << ')' << '\n';
}

point3D::~point3D()
{
	cout << "Point3D Destroyed!" << '\n';
}
