#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

void calculate_center(float h, float k)
{
	printf("Center: (%lf, %lf)\n", h, k);
}

void calculate_radius(float x, float y, float h, float k)
{
	float output = sqrt((float) pow((x - h), 2)) + ((float) pow((y - k), 2));
	printf("Radius: %lf\n", output);
}

#endif