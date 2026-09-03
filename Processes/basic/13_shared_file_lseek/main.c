#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{

	printf("\n\nShared File Lseek Modification\n\n");

	const char *filename = "data.txt";

	int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);

	if(fd < 0){

		perror("[ERROR] Failed to open file");
		return 1;

	}

	char buffer_8[10] = "0000000000";

	if(write(fd, buffer_8, 10) != 10){

		perror("[ERROR] Failed initial write");
		close(fd);
		return 1;

	}

	pid_t child_9 = fork();

	if(child_9 < 0){

		perror("[ERROR] fork child 9 failed");
		close(fd);
		return 1;

	}

	if(child_9 == 0){

		//CHILD
		char child_buf[4] = "XXXX";

		if(lseek(fd, 3, SEEK_SET) == -1){

			perror("[ERROR] lseek child failed");
			close(fd);
			exit(1);

		}

		if(write(fd, child_buf, 4) != 4){

			perror("[ERROR] write child failed");
			close(fd);
			exit(1);

		}

		close(fd);
		exit(0);

	}else{

		//PARENT
		wait(NULL);

		if(lseek(fd, 0, SEEK_SET) == -1){

			perror("[ERROR] lseek parent failed");
			close(fd);
			return 1;

		}

		char ch_buf_read[11];
		ssize_t bytes = read(fd, ch_buf_read, 10);

		if(bytes < 0){

			perror("[ERROR] read parent failed");
			close(fd);
			return 1;

		}

		ch_buf_read[bytes] = '\0';

		printf("\n[PARENT] -> File content after child lseek write: %s\n", ch_buf_read);

		close(fd);

	}

	return 0;

}
