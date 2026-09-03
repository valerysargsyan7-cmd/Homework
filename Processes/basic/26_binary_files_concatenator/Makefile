CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = binary_files_concatenator

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) arr1.bin arr2.bin

.PHONY: all clean
