CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = signal_synchronized_file_read

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) Parent.txt

.PHONY: all clean
