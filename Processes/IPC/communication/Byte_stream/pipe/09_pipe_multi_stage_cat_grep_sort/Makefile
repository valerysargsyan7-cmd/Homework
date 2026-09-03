CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = pipe_multi_stage_cat_grep_sort

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) data.txt

.PHONY: all clean
