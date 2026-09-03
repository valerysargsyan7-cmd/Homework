#include <stdio.h>
#include "geometry.h"

#define PI 3.14159265358979323846f

float rectangle_surface(float length, float width)
{

	if(length <= 0.0f || width <= 0.0f){

		printf("[WARNING] Invalid rectangle dimensions (length=%.2f, width=%.2f)\n", length, width);
		return 0.0f;

	}

	return length * width;

}

float circle_perimeter(float radius)
{

	if(radius <= 0.0f){

		printf("[WARNING] Invalid circle radius (radius=%.2f)\n", radius);
		return 0.0f;

	}

	return 2.0f * PI * radius;

}
