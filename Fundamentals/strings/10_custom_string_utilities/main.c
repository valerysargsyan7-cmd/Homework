#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "str_utils.h"

int main()
{

	printf("\n\nCustom String Utilities Module\n\n");

	char string[128];
	printf("Enter a string: ");
	if(scanf("%127s", string) != 1){

		fprintf(stderr, "[ERROR] Invalid input.\n");
		return 1;

	}

	int string_length = my_strlen(string);
	printf("\nThe length of string is: %d\n", string_length);

	char searching_char = 0;
	printf("Enter the letter you want to find: ");
	if(scanf(" %c", &searching_char) != 1){

		fprintf(stderr, "[ERROR] Invalid character input.\n");
		return 1;

	}

	char *found_char = my_strchr(string, searching_char);

	if(found_char != NULL){

		printf("\n[SUCCESS] Letter found! Substring from character: \"%s\"\n", found_char);

	}else{

		printf("\n[INFO] Character '%c' was not found in \"%s\".\n", searching_char, string);

	}

	return 0;

}
