CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = season_temperature

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean