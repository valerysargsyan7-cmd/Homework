#include <stdio.h>
#include <signal.h>

int main()
{

	printf("\n\nSignal Set\n\n");

	sigset_t set;


	if(sigemptyset(&set) == -1){

		perror("[ERROR] sigemptyset failed");
		return 1;

	}


	if(sigaddset(&set, SIGINT) == -1){

		perror("[ERROR] sigaddset failed");
		return 1;

	}


	if(sigismember(&set, SIGINT) == 1){

		printf("\nSIGINT EXISTS\n");

	}else{

		printf("\nSIGINT DOESN'T EXIST\n");

	}


	if(sigismember(&set, SIGTERM) == 1){

		printf("\nSIGTERM EXISTS\n");

	}else{

		printf("\nSIGTERM DOESN'T EXIST\n");

	}


	return 0;

}