#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "sentinel.h"

volatile sig_atomic_t sigint_flag = 0;

void sigint_handler(int sig_num)
{
	(void)sig_num;
	sigint_flag = 1;
}

int main()
{

	printf("\n\nMemory Leak Sentinel Module\n\n");

	if(signal(SIGINT, sigint_handler) == SIG_ERR){

		perror("[ERROR] signal registration failed");
		return 1;

	}

	printf("Allocating sample heap buffers via safe_malloc()...\n");

	void *p1 = safe_malloc(10);
	void *p2 = safe_malloc(20);
	void *p3 = safe_malloc(50);
	void *p4 = safe_malloc(100);
	void *p5 = safe_malloc(200);

	(void)p1;
	(void)p3;
	(void)p5;

	// Intentionally free some pointers to simulate normal workflow
	printf("Explicitly freeing 2 pointers with safe_free()...\n");
	safe_free(p2);
	safe_free(p4);

	printf("3 allocated buffers remain untracked by caller (simulated leaks).\n");
	printf("Press Ctrl+C (or wait 2s) to trigger force_cleanup()...\n");

	for(int i = 0; i < 2; i++){

		if(sigint_flag){

			break;

		}

		sleep(1);

	}

	printf("\nTriggering sentinel sweep...\n");
	force_cleanup();

	printf("Program exiting cleanly.\n");

	return 0;

}
