#include <stdio.h>
#include <stdlib.h>


int main()
{

	printf("\n\nPointer Replace\n\n");

	int x = 0;
	int y = 0;

	int *ptr_x = &x;
	int *ptr_y = &y;

	printf("\nEnter first number to replace: ");

	if(scanf("%d", &x) != 1){

		printf("[ERROR] Invalid input for first number!\n");
		return 1;

	}


	printf("\nEnter second number to replace: ");

	if(scanf("%d", &y) != 1){

		printf("[ERROR] Invalid input for second number!\n");
		return 1;

	}


	printf("\nWithout replacing: %d, %d\n", *ptr_x, *ptr_y);


	int tmp = *ptr_x;
	*ptr_x = *ptr_y;
	*ptr_y = tmp;


	printf("With replace: %d, %d\n", *ptr_x, *ptr_y);

	printf("Difference: %d\n", abs(*ptr_x - *ptr_y));


	return 0;
}