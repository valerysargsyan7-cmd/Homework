#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int create_and_write(const char *filename, const char *content);
long read_and_print(const char *filename);

int main()
{

	printf("\n\nPOSIX File Create, Write, and Read\n\n");

	const char *filename = "Read_write_text.txt";
	const char *content = "Hello this is my first file that i create by C code and system calls\n";

	int result = create_and_write(filename, content);
	printf("\nBytes written: %d\n", result);

	int result_of_read = read_and_print(filename);
	printf("\nBytes read: %d\n", result_of_read);

	return 0;

}

int create_and_write(const char *filename, const char *content)
{

	int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0664);

	if(fd < 0){

		perror("[ERROR] open failed in create_and_write");
		return -1;

	}

	size_t content_length = strlen(content);
	ssize_t bytes_written = write(fd, content, content_length);

	if(bytes_written < 0){

		perror("[ERROR] write failed");
		close(fd);
		return -1;

	}

	close(fd);
	return (int)bytes_written;

}

long read_and_print(const char *filename)
{

	int fd = open(filename, O_RDONLY);

	if(fd < 0){

		perror("[ERROR] open failed in read_and_print");
		return -1;

	}

	char buf[1024];
	ssize_t bytes_read = read(fd, buf, sizeof(buf) - 1);

	if(bytes_read < 0){

		perror("[ERROR] read failed");
		close(fd);
		return -1;

	}

	buf[bytes_read] = '\0';
	printf("TEXT: %s", buf);

	close(fd);
	return (long)bytes_read;

}
