CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = parallel_max_search

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) search_dataset.bin

.PHONY: all clean
