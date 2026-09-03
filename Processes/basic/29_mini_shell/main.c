#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "executor.h"

int main()
{

	printf("\n==============================\n");
	printf("||        MINI SHELL        ||\n");
	printf("==============================\n\n");

	char line[1024];

	while(1){

		printf("mini_shell> ");
		fflush(stdout);

		if(fgets(line, sizeof(line), stdin) == NULL){

			printf("\nExiting mini_shell...\n");
			break;

		}

		size_t line_len = strlen(line);

		if(line_len > 0 && line[line_len - 1] == '\n'){

			line[line_len - 1] = '\0';
			line_len--;

		}

		if(line_len == 0){

			continue;

		}

		if(strcmp(line, "exit") == 0){

			printf("\nGoodbye from mini_shell!\n");
			break;

		}

		char **args = parser(line);

		if(args != NULL){

			execute_cmd(args);
			free(args);

		}

	}

	return 0;

}
