CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = time_calc

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean