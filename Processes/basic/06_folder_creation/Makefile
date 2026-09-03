CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = folder_creation

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)
	rm -rf NewHomework

.PHONY: all clean
