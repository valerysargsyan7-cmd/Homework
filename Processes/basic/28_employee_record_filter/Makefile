CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = employee_record_filter

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) employees.bin

.PHONY: all clean
