#include "./point.h"
#ifndef POINT3D_H_INCLUDED
#define POINT3D_H_INCLUDED

class point3D : public point
{
public:
	point3D();
	point3D(double);
	point3D(double, double);
	point3D(double, double, double);
	void setZ(double);
	double getZ();
	void draw();
	~point3D();

protected:
	double _z;
};

#endif
