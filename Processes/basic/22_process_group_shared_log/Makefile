CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = process_group_shared_log

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) group_log.txt

.PHONY: all clean
