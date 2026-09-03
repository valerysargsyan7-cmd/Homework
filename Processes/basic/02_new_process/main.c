#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

	printf("\n\nNew Process\n\n");

	pid_t pid = fork();


	if(pid < 0){

		perror("[ERROR] fork failed");
		return 1;

	}else if(pid == 0){

		//CHILD

		printf("\n[CHILD] -> Hello I am the Child process!\n");
		printf("Child PID: %d\n", getpid());

	}else{

		//PARENT

		printf("\n[PARENT] -> Hello I am the Parent process!\n");
		printf("Parent PID: %d\n", getpid());

	}


	return 0;

}