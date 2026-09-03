CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17 -D_POSIX_C_SOURCE=200809L -D_DEFAULT_SOURCE
TARGET = process_task_spawner

SRCS = main.c proc_utils.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
