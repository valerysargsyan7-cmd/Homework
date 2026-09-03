CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = dynamic_array_factory

SRCS = main.c mem_helper.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
