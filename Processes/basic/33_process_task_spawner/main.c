#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "proc_utils.h"

void print_working(void);

int main()
{

	printf("\n\nProcess Task Spawner Framework\n\n");

	pid_t child_pid = spawn_task(print_working);

	if(child_pid > 0){

		printf("[PARENT] -> Waiting for child task with PID: %d...\n", child_pid);

		waitpid(child_pid, NULL, 0);

		printf("[PARENT] -> Child task finished. Exiting.\n");

	}

	return 0;

}

void print_working(void)
{

	for(int i = 0; i < 5; i++){

		printf("  [WORKER] -> Processing batch %d/5...\n", i + 1);
		usleep(200000); // 200ms

	}

}
