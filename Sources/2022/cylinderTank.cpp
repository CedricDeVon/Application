#include <iostream>
#include <cmath>

#include "./cylinderTank.h"

using namespace std;

cylinderTank::cylinderTank()
{
	height = 0;
	radius = 0;
	aveDrainRate = 0;
	aveFillRate = 0;
}

void cylinderTank::setHeight(double newHeight)
{
	height = (newHeight >= 0) ? newHeight : 0;
}

void cylinderTank::setRadius(double newRadius)
{
	radius = (newRadius >= 0) ? newRadius : 0;
}

void cylinderTank::setDrainRate(double newAveDrainRate)
{
	aveDrainRate = (newAveDrainRate >= 0) ? newAveDrainRate : 0;
}

void cylinderTank::setFillRate(double newAveFillRate)
{
	aveFillRate = (newAveFillRate >= 0) ? newAveFillRate : 0;
}

double cylinderTank::getHeight()
{
	return height;
}

double cylinderTank::getRadius()
{
	return radius;
}

double cylinderTank::getDrainRate()
{
	return aveDrainRate;
}

double cylinderTank::getFillRate()
{
	return aveFillRate;
}

double cylinderTank::volume()
{
	return (radius > 0 && height > 0) ?
		((2 * acos(0.0)) * pow(radius, 2) * height) : 0;
}

void cylinderTank::timeToFillEmpty()
{
	int totalSecondsToFill = (aveFillRate > 0) ?
		static_cast<int>((volume() * 1000) / aveFillRate) : 0;
	cout << totalSecondsToFill / 3600 << ":"
		<< totalSecondsToFill / 60 % 60 << ":"
		<< totalSecondsToFill % 60 << '\n';
}

void cylinderTank::timeToFillPartial(double partialVolume)
{
	int totalSecondsToFill = (aveFillRate > 0 && (volume() - partialVolume > 0)) ?
		static_cast<int>(((volume() - partialVolume) * 1000) / aveFillRate) : 0;
	cout << totalSecondsToFill / 3600 << ":"
		<< totalSecondsToFill / 60 % 60 << ":"
		<< totalSecondsToFill % 60 << '\n';
}

cylinderTank::~cylinderTank()
{

}
