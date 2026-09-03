#include <stdio.h>


int compareing(int *first_number_ptr, int *second_number_ptr, int *are_equal_ptr);


int main()
{
	printf("\n\nCompareing two numbers\n\n");

	int first_num = 0;
	int second_num = 0;

	printf("Enter your first number: ");

	if(scanf("%d", &first_num) != 1){

		fprintf(stderr, "[ERROR] Invalid input for first number.\n");
		return 1;

	}

	printf("Enter your second number: ");

	if(scanf("%d", &second_num) != 1){

		fprintf(stderr, "[ERROR] Invalid input for second number.\n");
		return 1;

	}

	int are_equal = 0;

	int result = compareing(&first_num, &second_num, &are_equal);

	if(are_equal){

		printf("[ERROR] Numbers are equal.\n");

	}else{

		printf("Maximum number: %d\n", result);

	}


	return 0;
}



int compareing(int *first_number_ptr, int *second_number_ptr, int *are_equal_ptr)
{
	if(*first_number_ptr < *second_number_ptr){

		*are_equal_ptr = 0;
		return *second_number_ptr;

	}else if(*first_number_ptr > *second_number_ptr){

		*are_equal_ptr = 0;
		return *first_number_ptr;

	}else{

		*are_equal_ptr = 1;
		return 0;

	}
}