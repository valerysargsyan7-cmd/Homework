CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = replace_char_mmap

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) replace_sample.txt

.PHONY: all clean
