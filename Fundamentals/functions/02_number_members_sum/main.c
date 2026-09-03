#include <stdio.h>


void num_mem_summing(int summing_num, int *sum_ptr);


int main()
{
	printf("\n\nNumber members sum\n\n");

	int summing_mem_num = 0;

	printf("Enter number: ");

	if(scanf("%d", &summing_mem_num) != 1){

		fprintf(stderr, "[ERROR] Invalid input. Please enter an integer.\n");
		return 1;

	}


	int result = 0;

	num_mem_summing(summing_mem_num, &result);

	printf("Sum of members: %d\n", result);


	return 0;
}



void num_mem_summing(int summing_num, int *sum_ptr)
{
	int sum = 0;

	if(summing_num < 0){

		summing_num = -summing_num;

	}

	while(summing_num > 0){

		sum += summing_num % 10;
		summing_num /= 10;

	}

	*sum_ptr = sum;
}

