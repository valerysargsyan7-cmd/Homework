CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = parallel_matrix_row_multiplier

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) matrix.bin row1.bin row2.bin row3.bin

.PHONY: all clean
