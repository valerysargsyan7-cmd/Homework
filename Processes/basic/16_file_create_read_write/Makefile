CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = file_create_read_write

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) Practice_07_06_26_file.txt

.PHONY: all clean
