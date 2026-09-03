#include <stdio.h>

int is_prime(int n);

int main()
{
	printf("\n\nIs Prime\n\n");

	int prime[10];

	int *prime_ptr = prime;


	for(int i = 0; i < 10; i++){

		printf("Enter your %dth number: ", i + 1);

		if(scanf("%d", prime_ptr + i) != 1){

			fprintf(stderr, "[ERROR] Invalid input at element %d.\n", i + 1);
			return 1;

		}


		if(is_prime(*(prime_ptr + i))){

			printf("Prime: %d\n", *(prime_ptr + i));

		}

	}


	return 0;
}



int is_prime(int n)
{
	if(n < 2){

		return 0;

	}


	for(int i = 2; i <= n / i; i++){

		if(n % i == 0){

			return 0;

		}

	}


	return 1;
}
