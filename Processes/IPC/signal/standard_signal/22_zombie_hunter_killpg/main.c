#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "zombie_hunter.h"

int main()
{

	printf("\n\nZombie Hunter (killpg & Non-Blocking Reaping)\n\n");

	pid_t pids[5];
	pid_t target_pgid = 0;

	for(int i = 0; i < 5; i++){

		pids[i] = fork();

		if(pids[i] < 0){

			perror("[ERROR] fork failed");
			return 1;

		}

		if(pids[i] == 0){

			//CHILD: loop waiting for termination
			while(1){

				pause();

			}

		}else{

			if(i == 0){

				target_pgid = pids[0];

			}

			setpgid(pids[i], target_pgid);

		}

	}

	printf("[PARENT] -> 5 worker processes spawned into Process Group %d.\n", target_pgid);
	printf("[PARENT] -> Initiating zombie hunt and reap cycle...\n\n");

	hunt_zombies(target_pgid);

	printf("\n[PARENT] -> All zombie processes reaped successfully.\n");

	return 0;

}
