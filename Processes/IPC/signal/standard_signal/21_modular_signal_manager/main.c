#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "sig_manager.h"

volatile sig_atomic_t sigint_handled_count = 0;

void handler(int sig_num)
{

	(void)sig_num;

	sigset_t set;
	sigset_t old_set;
	sigfillset(&set);

	sigprocmask(SIG_BLOCK, &set, &old_set);

	sigint_handled_count++;
	const char msg[] = "\n[HANDLER] -> Signal handled inside protected critical section!\n";
	write(STDOUT_FILENO, msg, sizeof(msg) - 1);

	sigprocmask(SIG_SETMASK, &old_set, NULL);

}

int main()
{

	printf("\n\nModular Signal Manager (Masked Critical Section)\n\n");
	printf("Registering handler for SIGINT (Ctrl+C)...\n");

	register_safe_handler(SIGINT, handler);

	printf("Running loop. Press Ctrl+C to trigger handler, or wait for automatic simulation.\n");

	for(int i = 0; i < 3; i++){

		printf("Loop step %d/3... (PID: %d)\n", i + 1, getpid());
		sleep(1);

	}

	printf("\nTriggering self SIGINT via raise()...\n");
	raise(SIGINT);

	printf("Signals handled: %d. Exiting cleanly.\n", (int)sigint_handled_count);

	return 0;

}
