#include <stdio.h>

void multiplication_table(int mult_num);

int main()
{

	printf("\n\nMultiplication Table\n\n");

	int multing_number = 0;


	printf("Enter number: ");

	if(scanf("%d", &multing_number) != 1){

		printf("\n[ERROR] Invalid input!\n");
		return 1;

	}


	printf("\n");

	multiplication_table(multing_number);


	return 0;

}



void multiplication_table(int mult_num){

	for(int i = 1; i <= 10; i++){

		printf("%d * %d = %d\n", mult_num, i, mult_num * i);

	}

}
