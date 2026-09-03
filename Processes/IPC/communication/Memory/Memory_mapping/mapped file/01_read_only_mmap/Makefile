CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = read_only_mmap

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) sample_mmap.txt

.PHONY: all clean
