#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class point
{
public:
	point();
	point(double);
	point(double, double);
	double getX();
	double getY();
	void setX(double);
	void setY(double);
	void draw();
	~point();

protected:
	double _x;
	double _y;
};

#endif
