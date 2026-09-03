CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = stdin_redirection_dup2

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) data.txt

.PHONY: all clean
