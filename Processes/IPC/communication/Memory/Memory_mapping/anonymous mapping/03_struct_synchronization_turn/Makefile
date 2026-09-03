CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17 -D_POSIX_C_SOURCE=200809L -D_DEFAULT_SOURCE
TARGET = struct_synchronization_turn

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
