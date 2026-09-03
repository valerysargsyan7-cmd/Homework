#include <stdio.h>

int count_vowels(char *str);

int main()
{

	printf("\n\nVowel Letter Counting\n\n");

	char vowel_string[200];

	printf("\nEnter your string with vowels: ");

	if(scanf("%199s", vowel_string) != 1){

		printf("[ERROR] Failed to read string!\n");
		return 1;

	}


	int count = count_vowels(vowel_string);

	printf("\nVowels: %d\n", count);


	return 0;
}


int count_vowels(char *str)
{

	char *start = str;
	int count = 0;

	while(*start != '\0'){

		if((*start == 'a' || *start == 'e' || *start == 'i' ||
		   *start == 'o' || *start == 'u') || (*start == 'A' || *start == 'E' || *start == 'I' ||
		   *start == 'O' || *start == 'U')){

			count++;

		}

		start++;

	}

	return count;
}
