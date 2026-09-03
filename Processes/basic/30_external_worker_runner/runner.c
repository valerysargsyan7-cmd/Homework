#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "runner.h"

void run_worker_bg(const char *arg)
{

	pid_t child = fork();

	if(child < 0){

		perror("[ERROR] fork failed in runner");
		return;

	}

	if(child == 0){

		execlp("./worker", "./worker", arg, NULL);
		perror("[ERROR] execlp failed");
		exit(1);

	}

}
