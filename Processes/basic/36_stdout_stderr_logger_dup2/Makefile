CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = stdout_stderr_logger_dup2

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET) app.log

.PHONY: all clean
