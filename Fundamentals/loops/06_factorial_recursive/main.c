#include <stdio.h>
#include <limits.h>

long long factorial(int n, int *overflow);

int main()
{

	printf("\n\nRecursive Factorial\n\n");

	int fac_num = 0;

	printf("\nEnter number for factorial: ");

	if(scanf("%d", &fac_num) != 1){

		printf("[ERROR] Invalid input!\n");
		return 1;

	}


	if(fac_num < 0){

		printf("[ERROR] Factorial cannot be calculated for a negative number!\n");
		return 1;

	}

	int overflow = 0;
	long long result = factorial(fac_num, &overflow);

	if(overflow){

		printf("[ERROR] Factorial too large to represent!");

	}

	printf("\nFactorial of this number %d is: %lld\n",
		   fac_num, result);


	return 0;
}


long long factorial(int n, int *overflow)
{

	if(n == 0 || n == 1){

		*overflow = 0;
		return 1;

	}


	long long sub_result = factorial(n - 1, overflow);

	if(*overflow){

		return 0;

	}

	if(sub_result > LLONG_MAX / n){

		*overflow = 1;
		return 0;

	}

	return n * sub_result;

}
