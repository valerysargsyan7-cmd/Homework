#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "proc_utils.h"

pid_t spawn_task(void (*task_func)(void))
{

	if(task_func == NULL){

		return -1;

	}

	pid_t child = fork();

	if(child < 0){

		perror("[ERROR] fork failed in spawn_task");
		return -1;

	}

	if(child == 0){

		//CHILD
		task_func();
		printf("\n[CHILD] -> Task execution completed. Exiting (PID: %d)...\n", getpid());
		exit(0);

	}else{

		//PARENT
		printf("[PARENT] -> Spawned worker child with PID: %d\n", child);
		return child;

	}

}
