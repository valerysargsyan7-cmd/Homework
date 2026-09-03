CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = multistage_signal_kill

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
