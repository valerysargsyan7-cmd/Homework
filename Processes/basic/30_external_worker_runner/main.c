#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "runner.h"

int main()
{

	printf("\n\nExternal Worker Runner\n\n");
	printf("[PARENT] -> Launching background worker process...\n");

	run_worker_bg("Task_Payload_Data_123");

	wait(NULL);

	printf("[PARENT] -> Worker process execution finished.\n");

	return 0;

}
