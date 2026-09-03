CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17
SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): server.c
	$(CC) $(CFLAGS) server.c -o $(SERVER)

$(CLIENT): client.c
	$(CC) $(CFLAGS) client.c -o $(CLIENT)

clean:
	rm -f $(SERVER) $(CLIENT) sample_doc.txt empty_doc.txt

.PHONY: all clean
