#include <stdio.h>

int main(int argc, char *argv[])
{

	if(argc > 1){

		printf("[WORKER] -> Received Argument: \"%s\" (PID: %d)\n", argv[1], getpid());

	}else{

		printf("[WORKER] -> No arguments provided (PID: %d)\n", getpid());

	}

	return 0;

}
