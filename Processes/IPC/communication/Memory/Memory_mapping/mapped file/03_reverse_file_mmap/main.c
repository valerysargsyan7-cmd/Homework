#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

void reverse_file_in_memory(const char *filepath);

int main()
{

	printf("\n\nIn-Place Whole-File Reversal via Mmap\n\n");

	const char *filepath = "reverse_sample.txt";

	FILE *fp = fopen(filepath, "w");
	if(fp != NULL){

		fprintf(fp, "ABCDEFGHIJKLM");
		fclose(fp);

	}

	printf("Original file '%s' content:\n", filepath);
	int read_fd = open(filepath, O_RDONLY);
	if(read_fd >= 0){

		char buf[128];
		ssize_t n = read(read_fd, buf, sizeof(buf) - 1);
		if(n > 0){

			buf[n] = '\0';
			printf("\"%s\"\n", buf);

		}
		close(read_fd);

	}

	printf("\nReversing file in-place via mmap()...\n");
	reverse_file_in_memory(filepath);

	printf("\nReversed file content on disk:\n");
	read_fd = open(filepath, O_RDONLY);
	if(read_fd >= 0){

		char buf[128];
		ssize_t n = read(read_fd, buf, sizeof(buf) - 1);
		if(n > 0){

			buf[n] = '\0';
			printf("\"%s\"\n", buf);

		}
		close(read_fd);

	}

	return 0;

}

void reverse_file_in_memory(const char *filepath)
{

	int fd = open(filepath, O_RDWR);

	if(fd < 0){

		perror("[ERROR] Failed to open file for read/write");
		return;

	}

	off_t text_size = lseek(fd, 0, SEEK_END);

	if(text_size <= 0){

		close(fd);
		return;

	}

	char *file_text = (char *)mmap(NULL, (size_t)text_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	if(file_text == MAP_FAILED){

		perror("[ERROR] mmap failed");
		close(fd);
		return;

	}

	char *start = file_text;
	char *end = file_text + text_size - 1;

	for(off_t i = 0; i < text_size / 2; i++){

		char temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;

	}

	munmap(file_text, (size_t)text_size);
	close(fd);

}
