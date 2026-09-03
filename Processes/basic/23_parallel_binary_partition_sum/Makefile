CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = parallel_binary_partition_sum

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) data.bin

.PHONY: all clean
