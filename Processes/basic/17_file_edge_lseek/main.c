#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void print_edges_sys(const char *filename);

int main()
{

	printf("\n\nFile Head & Tail Edge Reading with Lseek\n\n");

	const char *filename = "edges_sample.txt";

	int init_fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0664);

	if(init_fd >= 0){

		const char *sample = "Hello this is a complete sentence with edge words!\n";
		write(init_fd, sample, strlen(sample));
		close(init_fd);

	}

	print_edges_sys(filename);

	return 0;

}

void print_edges_sys(const char *filename)
{

	int fd = open(filename, O_RDONLY);

	if(fd < 0){

		perror("[ERROR] Failed to open file");
		return;

	}

	char res_of_read_start[16] = {0};

	ssize_t start_bytes = read(fd, res_of_read_start, 5);

	if(start_bytes > 0){

		res_of_read_start[start_bytes] = '\0';
		printf("START_TEXT (first 5 bytes): %s\n", res_of_read_start);

	}

	if(lseek(fd, -6, SEEK_END) == -1){

		perror("[ERROR] lseek failed");
		close(fd);
		return;

	}

	char res_of_read_end[16] = {0};

	ssize_t end_bytes = read(fd, res_of_read_end, 5);

	if(end_bytes > 0){

		res_of_read_end[end_bytes] = '\0';
		printf("END_TEXT (last 5 bytes): %s\n", res_of_read_end);

	}

	close(fd);

}
