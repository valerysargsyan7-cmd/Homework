CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = stdout_save_and_restore_dup

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) temp.txt

.PHONY: all clean
