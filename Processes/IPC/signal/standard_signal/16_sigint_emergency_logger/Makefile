CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = sigint_emergency_logger

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) SIGINT_info.txt

.PHONY: all clean
