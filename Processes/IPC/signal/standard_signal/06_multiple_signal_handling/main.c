#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t last_signal = 0;

void several_sig_handler(int sig_num)
{
	last_signal = sig_num;
}

int main()
{

	printf("\n\nHandling Different Signals\n\n");
	printf("Process PID: %d\n", getpid());
	printf("Listening for SIGINT (Ctrl+C), SIGTERM, and SIGUSR1...\n");

	if(signal(SIGINT, several_sig_handler) == SIG_ERR ||
	   signal(SIGTERM, several_sig_handler) == SIG_ERR ||
	   signal(SIGUSR1, several_sig_handler) == SIG_ERR){

		perror("[ERROR] signal registration failed");
		return 1;

	}

	while(1){

		if(last_signal != 0){

			switch(last_signal){

				case SIGINT:
					printf("\nCtrl+C pressed, but i won't stop!\n");
					break;

				case SIGTERM:
					printf("\nTermination request received, ignoring!\n");
					break;

				case SIGUSR1:
					printf("\nCustom user signal received!\n");
					break;

				default:
					printf("\nUnknown signal received: %d\n", last_signal);
					break;

			}

			last_signal = 0;

		}

		sleep(1);

	}

	return 0;

}
