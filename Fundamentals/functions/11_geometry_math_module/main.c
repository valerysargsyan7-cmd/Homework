#include <stdio.h>
#include <stdlib.h>

#include "geometry.h"

int main()
{

	printf("\n\nStatic Geometry Math Module\n\n");

	float rectangle_length = 0.0f;
	float rectangle_width = 0.0f;

	printf("Enter length of rectangle: ");
	if(scanf("%f", &rectangle_length) != 1){

		fprintf(stderr, "[ERROR] Invalid input.\n");
		return 1;

	}

	printf("Enter width of rectangle: ");
	if(scanf("%f", &rectangle_width) != 1){

		fprintf(stderr, "[ERROR] Invalid input.\n");
		return 1;

	}

	float circle_radius = 0.0f;

	printf("\nEnter radius of circle: ");
	if(scanf("%f", &circle_radius) != 1){

		fprintf(stderr, "[ERROR] Invalid input.\n");
		return 1;

	}

	float surface_of_rectangle = rectangle_surface(rectangle_length, rectangle_width);
	float perimeter_of_circle = circle_perimeter(circle_radius);

	printf("\n--- Calculation Results ---\n");
	printf("Surface of Rectangle (%.2f x %.2f) = %.2f\n",
	       rectangle_length, rectangle_width, surface_of_rectangle);
	printf("Perimeter of Circle (r = %.2f)       = %.2f\n",
	       circle_radius, perimeter_of_circle);

	printf("\nProgram status: DONE\n");

	return 0;

}
