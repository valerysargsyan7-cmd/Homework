#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "executor.h"

void execute_cmd(char **args)
{

	if(args == NULL || args[0] == NULL){

		return;

	}

	pid_t child = fork();

	if(child < 0){

		perror("[ERROR] fork failed");
		return;

	}

	if(child == 0){

		execvp(args[0], args);
		perror("[ERROR] execvp failed");
		exit(1);

	}else{

		wait(NULL);

	}

}
