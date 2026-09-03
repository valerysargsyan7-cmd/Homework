CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17 -D_POSIX_C_SOURCE=200809L
TARGET = signal_set

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean