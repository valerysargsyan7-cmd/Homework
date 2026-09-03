CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = file_lines_and_size

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) Reading_file.txt

.PHONY: all clean
