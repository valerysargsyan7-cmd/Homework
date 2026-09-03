#include <stdio.h>

int sum_of_digits(int n);

int main()
{

	printf("\n\nSum Of Digits\n\n");

	int num_digit = 0;

	printf("\nEnter number for summing digits: ");

	if(scanf("%d", &num_digit) != 1){

		printf("[ERROR] Invalid input!\n");
		return 1;

	}


	printf("\nThe sum of this number %d is: %d\n",
		   num_digit,
		   sum_of_digits(num_digit));


	return 0;
}


int sum_of_digits(int n)
{

	if(n < 0){

		n = -n;

	}


	if(n == 0){

		return 0;

	}


	return n % 10 + sum_of_digits(n / 10);

}
