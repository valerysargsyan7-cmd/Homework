#include <stdio.h>


struct Circle {

	float radius_of_circle;

};


int main()
{

	printf("\n\nCircle radius, surface, length\n\n");

	struct Circle radius;

	printf("\nEnter Circle radius: ");

	if(scanf("%f", &radius.radius_of_circle) != 1){

		printf("[ERROR] Invalid radius input!\n");
		return 1;

	}


	if(radius.radius_of_circle <= 0){

		printf("\n[ERROR] Invalid radius!\n");
		return 1;

	}


	float surface_of_circle = 3.14f * radius.radius_of_circle * radius.radius_of_circle;
	float length_of_circle = 2.0f * 3.14f * radius.radius_of_circle;


	printf("\nSurface: %.2f\n", surface_of_circle);
	printf("Length: %.2f\n", length_of_circle);


	return 0;
}