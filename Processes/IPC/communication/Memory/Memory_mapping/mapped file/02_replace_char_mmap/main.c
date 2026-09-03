#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

void replace_char_in_mmap(const char *filepath, char old_c, char new_c);

int main()
{

	printf("\n\nIn-Place Character Replacement via Mmap\n\n");

	const char *filepath = "replace_sample.txt";

	FILE *fp = fopen(filepath, "w");
	if(fp != NULL){

		fprintf(fp, "banana and apple and avocado\n");
		fclose(fp);

	}

	printf("Original file '%s' content:\n", filepath);
	int read_fd = open(filepath, O_RDONLY);
	if(read_fd >= 0){

		char buf[128];
		ssize_t n = read(read_fd, buf, sizeof(buf) - 1);
		if(n > 0){

			buf[n] = '\0';
			printf("%s", buf);

		}
		close(read_fd);

	}

	char old_c = 'a';
	char new_c = 'X';

	printf("\nReplacing all occurrences of '%c' with '%c' in-place via mmap()...\n", old_c, new_c);
	replace_char_in_mmap(filepath, old_c, new_c);

	printf("Modified file content after unmapping:\n");
	read_fd = open(filepath, O_RDONLY);
	if(read_fd >= 0){

		char buf[128];
		ssize_t n = read(read_fd, buf, sizeof(buf) - 1);
		if(n > 0){

			buf[n] = '\0';
			printf("%s", buf);

		}
		close(read_fd);

	}

	return 0;

}

void replace_char_in_mmap(const char *filepath, char old_c, char new_c)
{

	int fd = open(filepath, O_RDWR);

	if(fd < 0){

		perror("[ERROR] Failed to open file for read/write");
		return;

	}

	off_t text_bytes = lseek(fd, 0, SEEK_END);

	if(text_bytes <= 0){

		close(fd);
		return;

	}

	char *addr = (char *)mmap(NULL, (size_t)text_bytes, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	if(addr == MAP_FAILED){

		perror("[ERROR] mmap failed");
		close(fd);
		return;

	}

	for(off_t i = 0; i < text_bytes; i++){

		if(addr[i] == old_c){

			addr[i] = new_c;

		}

	}

	munmap(addr, (size_t)text_bytes);
	close(fd);

}
