CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = modular_parallel_sum

SRCS = main.c parallel_math.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) tmp_chunk_*.txt

.PHONY: all clean
