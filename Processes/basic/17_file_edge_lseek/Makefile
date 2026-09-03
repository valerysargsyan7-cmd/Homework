CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = file_edge_lseek

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) edges_sample.txt

.PHONY: all clean
