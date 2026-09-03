CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = multi_child_logger_group

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) audit.log

.PHONY: all clean
