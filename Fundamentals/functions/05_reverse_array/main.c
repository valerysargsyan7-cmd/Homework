#include <stdio.h>

void reverse(int *rev_array, int size_rev);

int main()
{
	printf("\n\nReversing Array\n\n");

	int rev_array[] = {1, 2, 3, 4, 5};
	int size_rev = sizeof(rev_array) / sizeof(rev_array[0]);

	reverse(rev_array, size_rev);


	printf("Reversed array: ");

	for(int i = 0; i < size_rev; i++){

		printf("%d ", rev_array[i]);

	}

	printf("\n");


	return 0;
}


void reverse(int *rev_array, int size_rev)
{
	if(rev_array == NULL || size_rev <= 0){

		return;

	}


	int *start_ptr = rev_array;
	int *end_ptr = rev_array + size_rev - 1;

	while(start_ptr < end_ptr){

		int tmp = *start_ptr;

		*start_ptr = *end_ptr;
		*end_ptr = tmp;

		start_ptr++;
		end_ptr--;

	}
}
