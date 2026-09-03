CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = posix_file_copy

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) Source_file.txt Destination_file.txt

.PHONY: all clean
