#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	printf("\n\nDynamic String Builder with Realloc\n\n");
	printf("Enter words to build a sentence. Enter 'STOP' to finish.\n\n");

	size_t capacity = 10;
	char *sentence = (char *)malloc(capacity);

	if(sentence == NULL){

		perror("[ERROR] Initial malloc failed");
		return 1;

	}

	sentence[0] = '\0';
	const char *stop_word = "STOP";
	char word[128];

	while(1){

		printf("Enter word: ");
		if(scanf("%127s", word) != 1){

			break;

		}

		if(strcmp(word, stop_word) == 0){

			printf("\n[STOP word received. Exiting input mode.]\n");
			break;

		}

		size_t word_length = strlen(word);
		size_t string_length = strlen(sentence);

		size_t needed = string_length + word_length + 2;

		if(needed > capacity){

			capacity = needed * 2;
			char *new_ptr = (char *)realloc(sentence, capacity);

			if(new_ptr == NULL){

				perror("[ERROR] realloc failed");
				free(sentence);
				return 1;

			}

			sentence = new_ptr;
			printf("  [Buffer expanded: new capacity = %zu bytes]\n", capacity);

		}

		if(string_length != 0){

			strcat(sentence, " ");

		}

		strcat(sentence, word);

	}

	printf("\n--- Assembled Sentence ---\n\"%s\"\n", sentence);
	printf("Total Length: %zu characters\n", strlen(sentence));

	free(sentence);
	printf("\nMemory freed successfully.\n");

	return 0;

}
