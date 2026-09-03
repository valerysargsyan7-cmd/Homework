#include <stdio.h>

int fibonacci(int n);

int main()
{

	printf("\n\nFibonacci\n\n");

	int fib_num = 0;

	printf("\nEnter number for Fibonacci: ");

	if(scanf("%d", &fib_num) != 1){

		printf("[ERROR] Invalid input!\n");
		return 1;

	}


	if(fib_num < 0){

		printf("[ERROR] Fibonacci index cannot be negative!\n");
		return 1;

	}


	printf("\n%d number's Fibonacci is: %d\n",
		   fib_num,
		   fibonacci(fib_num));


	return 0;
}




int fibonacci(int n)
{

	if(n == 0){

		return 0;

	}


	if(n == 1 || n == 2){

		return 1;

	}


	return fibonacci(n - 1) + fibonacci(n - 2);

}
