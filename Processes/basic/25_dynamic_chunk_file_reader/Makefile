CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = dynamic_chunk_file_reader

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) Parent_large_file.txt

.PHONY: all clean
