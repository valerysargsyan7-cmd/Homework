CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17 -D_POSIX_C_SOURCE=200809L
TARGET = external_runner
WORKER = worker

all: $(WORKER) $(TARGET)

$(WORKER): worker.c
	$(CC) $(CFLAGS) worker.c -o $(WORKER)

$(TARGET): main.o runner.o
	$(CC) $(CFLAGS) main.o runner.o -o $(TARGET)

main.o: main.c runner.h
	$(CC) $(CFLAGS) -c main.c -o main.o

runner.o: runner.c runner.h
	$(CC) $(CFLAGS) -c runner.c -o runner.o

clean:
	rm -f *.o $(TARGET) $(WORKER)

.PHONY: all clean
