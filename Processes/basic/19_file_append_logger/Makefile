CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = file_append_logger

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) File.log

.PHONY: all clean
