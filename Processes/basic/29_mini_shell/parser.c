#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

char **parser(char *command_string)
{

	int capacity = 5;
	int count = 0;

	char **args = (char **)malloc(capacity * sizeof(char *));

	if(args == NULL){

		perror("[ERROR] malloc failed in parser");
		return NULL;

	}

	int current_symbol = 0;
	int current_token = 0;
	int in_word = 0;

	while(command_string[current_symbol] != '\0'){

		if(command_string[current_symbol] == ' ' || command_string[current_symbol] == '\t'){

			in_word = 0;
			command_string[current_symbol] = '\0';

		}else{

			if(in_word == 0){

				args[current_token] = &command_string[current_symbol];
				current_token++;
				count++;

			}

			in_word = 1;

		}

		current_symbol++;

		if(count + 1 >= capacity){

			capacity *= 2;
			char **temp = (char **)realloc(args, capacity * sizeof(char *));

			if(temp == NULL){

				perror("[ERROR] realloc failed in parser");
				free(args);
				return NULL;

			}

			args = temp;

		}

	}

	args[current_token] = NULL;
	return args;

}
