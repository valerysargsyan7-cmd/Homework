#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "ping_pong.h"

int main()
{

	printf("\n\nModular Signal Ping-Pong (SIGUSR1)\n\n");

	pid_t child = fork();

	if(child < 0){

		perror("[ERROR] fork failed");
		return 1;

	}

	if(child == 0){

		//CHILD
		wait_ping();
		exit(0);

	}else{

		//PARENT
		printf("[PARENT] -> Sleeping 1 second before sending ping to child (PID: %d)...\n", child);
		sleep(1);

		printf("[PARENT] -> Sending ping (SIGUSR1) via send_ping()...\n");
		send_ping(child);

		wait(NULL);
		printf("[PARENT] -> Ping-pong exchange complete.\n");

	}

	return 0;

}
