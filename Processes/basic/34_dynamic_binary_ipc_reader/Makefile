CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = dynamic_binary_ipc_reader

SRCS = main.c ipc_buffer.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) rand_numbers.bin

.PHONY: all clean
