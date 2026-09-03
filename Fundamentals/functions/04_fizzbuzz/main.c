#include <stdio.h>

void fizzbuzz(int start, int end);

int main()
{
	printf("\n\nFizzBuzz\n\n");

	int first = 0;
	int second = 0;

	printf("Enter diapason first number: ");

	if(scanf("%d", &first) != 1){

		fprintf(stderr, "[ERROR] Invalid input for first number.\n");
		return 1;

	}

	printf("Enter diapason second number: ");

	if(scanf("%d", &second) != 1){

		fprintf(stderr, "[ERROR] Invalid input for second number.\n");
		return 1;

	}


	if(first > second){

		fprintf(stderr, "[ERROR] First number must be less than or equal to second number.\n");
		return 1;

	}


	fizzbuzz(first, second);


	return 0;
}




void fizzbuzz(int start, int end)
{
	for(int i = start; i <= end; i++){

		if(i % 15 == 0){

			printf("FIZZBUZZ\n");

		}else if(i % 3 == 0){

			printf("FIZZ\n");

		}else if(i % 5 == 0){

			printf("BUZZ\n");

		}else{

			printf("%d\n", i);

		}
	}
}
