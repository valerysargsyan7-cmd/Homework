CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = parallel_file_chunks

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) source.txt part1.txt part2.txt

.PHONY: all clean
