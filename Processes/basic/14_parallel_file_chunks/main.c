#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nParallel File Chunks Extraction\n\n");

	const char *src_filename = "source.txt";
	int init_fd = open(src_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);

	if(init_fd >= 0){

		write(init_fd, "0123456789ABCDEFGHIJ", 20);
		close(init_fd);

	}

	int fd = open(src_filename, O_RDONLY);

	if(fd < 0){

		perror("[ERROR] Failed to open source.txt");
		return 1;

	}

	pid_t child_10 = fork();

	if(child_10 < 0){

		perror("[ERROR] fork child 10 failed");
		close(fd);
		return 1;

	}

	if(child_10 == 0){

		//CHILD 10 reads chunk 1 (bytes 0-9)
		int fd_ch = open("part1.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);

		if(fd_ch < 0){

			perror("[ERROR] Failed to open part1.txt");
			close(fd);
			exit(1);

		}

		char buf_ch_10[11];
		ssize_t bytes_10 = pread(fd, buf_ch_10, 10, 0);

		if(bytes_10 > 0){

			write(fd_ch, buf_ch_10, bytes_10);

		}

		close(fd_ch);
		close(fd);
		exit(0);

	}else{

		pid_t child_11 = fork();

		if(child_11 < 0){

			perror("[ERROR] fork child 11 failed");
			wait(NULL);
			close(fd);
			return 1;

		}

		if(child_11 == 0){

			//CHILD 11 reads chunk 2 (bytes 10-19)
			int fd_ch_11 = open("part2.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);

			if(fd_ch_11 < 0){

				perror("[ERROR] Failed to open part2.txt");
				close(fd);
				exit(1);

			}

			char buf_ch_11[11];
			ssize_t bytes_11 = pread(fd, buf_ch_11, 10, 10);

			if(bytes_11 > 0){

				write(fd_ch_11, buf_ch_11, bytes_11);

			}

			close(fd_ch_11);
			close(fd);
			exit(0);

		}else{

			//PARENT
			wait(NULL);
			printf("[PARENT] -> Child 10 done (part1.txt written)\n");

			wait(NULL);
			printf("[PARENT] -> Child 11 done (part2.txt written)\n");

			close(fd);

			FILE *fp1 = fopen("part1.txt", "r");
			FILE *fp2 = fopen("part2.txt", "r");

			if(fp1 && fp2){

				char p1[16] = {0}, p2[16] = {0};
				fread(p1, 1, 10, fp1);
				fread(p2, 1, 10, fp2);
				printf("\nVerification:\nPart 1: %s\nPart 2: %s\n", p1, p2);
				fclose(fp1);
				fclose(fp2);

			}

		}

	}

	return 0;

}
