#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#include "zombie_hunter.h"

void hunt_zombies(pid_t pgid)
{

	int status;
	pid_t died_pid;

	printf("[HUNTER] -> Issuing killpg(PGID: %d, SIGKILL)...\n", pgid);
	killpg(pgid, SIGKILL);

	// Wait briefly to allow OS signal dispatch
	usleep(100000); // 100ms

	while((died_pid = waitpid(-1, &status, WNOHANG)) > 0){

		printf("[HUNTER] -> Process %d reaped from kernel process table (status: %d).\n",
		       died_pid, status);

	}

}
