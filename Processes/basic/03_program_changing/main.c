#include <stdio.h>
#include <unistd.h>

int main()
{

	printf("\n\nProgram Changing\n\n");

	printf("Current directory:\n");


	if(execlp("pwd", "pwd", NULL) == -1){

		perror("[ERROR] execlp failed");
		return 1;

	}


	return 0;

}