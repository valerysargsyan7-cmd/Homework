CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = shared_file_lseek

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) data.txt

.PHONY: all clean
