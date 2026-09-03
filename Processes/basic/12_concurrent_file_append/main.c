#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nConcurrent File Append\n\n");

	const char *filename = "report.txt";

	int fd = open(filename, O_CREAT | O_WRONLY | O_APPEND | O_TRUNC, 0644);

	if(fd < 0){

		perror("[ERROR] Failed to open file");
		return 1;

	}

	pid_t child_7 = fork();

	if(child_7 < 0){

		perror("[ERROR] fork child 7 failed");
		close(fd);
		return 1;

	}

	if(child_7 == 0){

		//CHILD 7
		char buffer_7[6] = "AAAA\n";

		for(int i = 0; i < 5; i++){

			if(write(fd, buffer_7, 5) != 5){

				perror("[ERROR] write child 7 failed");

			}

		}

		close(fd);
		exit(0);

	}else{

		pid_t child_8 = fork();

		if(child_8 < 0){

			perror("[ERROR] fork child 8 failed");
			wait(NULL);
			close(fd);
			return 1;

		}

		if(child_8 == 0){

			//CHILD 8
			char buffer_8[6] = "BBBB\n";

			for(int j = 0; j < 5; j++){

				if(write(fd, buffer_8, 5) != 5){

					perror("[ERROR] write child 8 failed");

				}

			}

			close(fd);
			exit(0);

		}else{

			//PARENT
			wait(NULL);
			wait(NULL);
			close(fd);

			printf("\n[PARENT] -> Both children finished writing to %s.\n", filename);

			FILE *fp = fopen(filename, "r");
			if(fp != NULL){

				char line[32];
				printf("\n--- File Content (%s) ---\n", filename);
				while(fgets(line, sizeof(line), fp)){

					printf("%s", line);

				}
				fclose(fp);

			}

		}

	}

	return 0;

}
