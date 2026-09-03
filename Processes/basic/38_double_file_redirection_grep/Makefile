CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = double_file_redirection_grep

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) input.log errors.txt

.PHONY: all clean
