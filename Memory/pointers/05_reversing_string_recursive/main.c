#include <stdio.h>

void reversing_string(char *str_ptr);

int main()
{
	printf("\n\nReversing String\n\n");

	char string[50];

	printf("\nEnter string: ");

	if(scanf("%49s", string) != 1){

		printf("[ERROR] Failed to read string!\n");
		return 1;

	}


	printf("\nReversed string: ");

	reversing_string(string);

	printf("\n");


	return 0;
}



void reversing_string(char *str_ptr)
{

	if(*str_ptr == '\0'){

		return;

	}


	reversing_string(str_ptr + 1);

	printf("%c", *str_ptr);

}