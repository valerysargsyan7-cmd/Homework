CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
TARGET = soccer_team_db

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean