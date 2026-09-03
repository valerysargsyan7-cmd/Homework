CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = private_vs_shared_mmap

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) cow_sample.txt

.PHONY: all clean
