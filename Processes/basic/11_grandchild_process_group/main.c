#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nProcess Hierarchy & Grandchild Process Group\n\n");

	pid_t child = fork();

	if(child < 0){

		perror("[ERROR] Fork failed");
		return 1;

	}else if(child == 0){

		//CHILD
		printf("\n[CHILD] -> PID: %d, PGID: %d\n", getpid(), getpgid(0));

		pid_t grandkid = fork();

		if(grandkid < 0){

			perror("[ERROR] Grandchild fork failed");
			exit(1);

		}else if(grandkid == 0){

			//GRANDCHILD
			if(setpgid(0, 0) == -1){

				perror("[ERROR] setpgid failed");
				exit(1);

			}

			printf("[GRANDCHILD] -> PID: %d, PGID: %d\n", getpid(), getpgid(0));
			exit(0);

		}else{

			wait(NULL);
			printf("[CHILD] -> Grandchild finished.\n");
			exit(0);

		}

	}else{

		//PARENT
		printf("[PARENT] -> PID: %d, PGID: %d\n", getpid(), getpgid(0));
		wait(NULL);
		printf("\n[PARENT] -> Child finished.\n");

	}

	return 0;

}
