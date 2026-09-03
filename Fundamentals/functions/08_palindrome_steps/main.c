#include <stdio.h>
#include <limits.h>

int reversing_number(int a, int *overflowed);
void palindrome_step(int a, int *steps, int *final_palindrome);

int main()
{
	printf("\n\nPalindrome steps\n\n");

	int a = 0;
	int steps = 0;
	int result_of_palindrome = 0;


	printf("Enter your number: ");

	if(scanf("%d", &a) != 1){

		fprintf(stderr, "[ERROR] Invalid input. Please enter an integer.\n");
		return 1;

	}


	palindrome_step(a, &steps, &result_of_palindrome);


	if(steps == -1){

		printf("[ERROR] Could not find palindrome safely.\n");
		return 1;

	}


	printf("Steps: %d\n", steps);
	printf("Palindrome: %d\n", result_of_palindrome);


	return 0;
}


int reversing_number(int a, int *overflowed)
{
	int rev = 0;
	*overflowed = 0;

	while(a != 0){

		int num = a % 10;

		if(rev > (INT_MAX - num) / 10){

			*overflowed = 1;
			return 0;

		}

		rev = rev * 10 + num;

		a /= 10;

	}


	return rev;
}


void palindrome_step(int a, int *steps, int *final_palindrome)
{
	int step_count = 0;


	if(a < 0){

		a = -a;

	}


	while(1){

		int overflowed = 0;
		int rev = reversing_number(a, &overflowed);


		if(overflowed){

			*steps = -1;
			*final_palindrome = 0;
			return;

		}


		if(a == rev){

			*final_palindrome = a;
			*steps = step_count;
			return;

		}

		if(a > (INT_MAX - rev)){

			*steps = -1;
			*final_palindrome = 0;
			return;

		}


		a = a + rev;
		step_count++;


		if(step_count == 10000){

			*steps = -1;
			*final_palindrome = 0;

			return;

		}

	}
}
