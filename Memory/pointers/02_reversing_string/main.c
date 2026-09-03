#include <stdio.h>

void reversing_string(char *string_reversing);

int main()
{

	printf("\n\nReversing String By Pointer\n\n");

	char string_reversing[200];

	printf("\nEnter your string: ");

	if(scanf("%199s", string_reversing) != 1){

		printf("[ERROR] Failed to read string!\n");
		return 1;

	}


	reversing_string(string_reversing);

	printf("\nReversed: %s\n", string_reversing);


	return 0;
}



void reversing_string(char *string_reversing)
{

	char *first = string_reversing;
	char *end = string_reversing;
	char tmp_str;

	while(*end != '\0'){

		end++;

	}

	end--;


	while(first < end){

		tmp_str = *first;
		*first = *end;
		*end = tmp_str;

		end--;
		first++;

	}

}
