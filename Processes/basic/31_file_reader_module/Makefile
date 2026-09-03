CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = file_reader_module

SRCS = main.c file_reader.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) sample_data.txt

.PHONY: all clean
