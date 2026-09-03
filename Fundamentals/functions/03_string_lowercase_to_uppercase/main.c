#include <stdio.h>

int isAlpha(char c);
void changeLetters(char *str);

int main()
{
	printf("\n\nString lowercase to uppercase changing\n\n");

	char string[20];

	printf("Enter your string: ");

	if(scanf("%19s", string) != 1){

		fprintf(stderr, "[ERROR] Failed to read string.\n");
		return 1;

	}


	changeLetters(string);

	printf("Result: %s\n", string);


	return 0;
}



int isAlpha(char c)
{
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){

		return 1;

	}

	return 0;
}


void changeLetters(char *str)
{
	while(*str != '\0'){

		if(isAlpha(*str)){

			if(*str >= 'a' && *str <= 'z'){

				*str = *str - 32;

			}

		}

		str++;

	}
}
