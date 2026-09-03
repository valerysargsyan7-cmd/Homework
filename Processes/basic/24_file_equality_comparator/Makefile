CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = file_equality_comparator

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) test1.txt test2.txt test3.txt

.PHONY: all clean
