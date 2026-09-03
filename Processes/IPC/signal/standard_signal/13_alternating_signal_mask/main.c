#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{

	printf("\n\nAlternating Signal Mask (Safe vs Dangerous Zones)\n\n");

	int it_num = 0;

	sigset_t set;

	if(sigemptyset(&set) == -1 || sigaddset(&set, SIGINT) == -1){

		perror("[ERROR] Signal set initialization failed");
		return 1;

	}

	while(it_num < 5){

		if(sigprocmask(SIG_BLOCK, &set, NULL) == -1){

			perror("[ERROR] sigprocmask block failed");
			return 1;

		}

		printf("\n[Iteration %d/5] Entered Safe Zone (Ctrl+C turned OFF)...\n", it_num + 1);
		fflush(stdout);
		sleep(2);

		if(sigprocmask(SIG_UNBLOCK, &set, NULL) == -1){

			perror("[ERROR] sigprocmask unblock failed");
			return 1;

		}

		printf("[Iteration %d/5] Entered Dangerous Zone (Ctrl+C turned ON)...\n", it_num + 1);
		fflush(stdout);
		sleep(2);

		it_num++;

	}

	printf("\nCompleted all 5 iterations successfully.\n");

	return 0;

}
