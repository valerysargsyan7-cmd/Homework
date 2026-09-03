#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nSignal Mask Inheritance\n\n");

	sigset_t set;

	if(sigemptyset(&set) == -1 ||
	   sigaddset(&set, SIGINT) == -1 ||
	   sigprocmask(SIG_BLOCK, &set, NULL) == -1){

		perror("[ERROR] Signal mask configuration failed");
		return 1;

	}

	printf("[PARENT] -> SIGINT (Ctrl+C) is now blocked.\n");

	pid_t child_proc = fork();

	if(child_proc < 0){

		perror("[ERROR] fork failed");
		return 1;

	}else if(child_proc == 0){

		//CHILD
		printf("\n[CHILD] -> I inherited the signal mask!\n");
		printf("[CHILD] -> Unblocking SIGINT...\n");

		if(sigprocmask(SIG_UNBLOCK, &set, NULL) == -1){

			perror("[ERROR] Failed to unblock SIGINT in child");
			exit(1);

		}

		printf("[CHILD] -> SIGINT is unblocked. Sleeping 5 seconds...\n");
		sleep(5);

		printf("\n[CHILD] -> Exiting by myself\n");
		exit(0);

	}else{

		//PARENT
		wait(NULL);
		printf("\n[PARENT] -> Child is done\n");

	}

	return 0;

}
