#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define TEXT_SIZE 5000
#define MAX_CONNECT 5

int main()
{

	printf("\n============================================\n");
	printf("||      REMOTE LOGGER SOCKET SERVER       ||\n");
	printf("============================================\n\n");

	struct sockaddr_in server;
	struct sockaddr_in client;
	socklen_t client_size = sizeof(client);

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0){

		perror("[ERROR] Failed to create socket");
		return 1;

	}

	int opt = 1;
	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0){

		perror("[WARNING] setsockopt SO_REUSEADDR failed");

	}

	if(bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){

		perror("[ERROR] Bind error on port 8080");
		close(sockfd);
		return 1;

	}

	if(listen(sockfd, MAX_CONNECT) < 0){

		perror("[ERROR] Listen error");
		close(sockfd);
		return 1;

	}

	printf("Logger daemon listening on port %d... Waiting for incoming logs...\n", PORT);

	int client_fd = accept(sockfd, (struct sockaddr *)&client, &client_size);

	if(client_fd < 0){

		perror("[ERROR] Accept connection failed");
		close(sockfd);
		return 1;

	}

	printf("\n[SUCCESS] Client connected! (IP: %s, Port: %d)\n",
	       inet_ntoa(client.sin_addr), ntohs(client.sin_port));

	const char *log_path = "server_logs.txt";
	int log_fd = open(log_path, O_WRONLY | O_CREAT | O_APPEND, 0644);

	if(log_fd < 0){

		perror("[ERROR] Failed to open server_logs.txt");
		close(client_fd);
		close(sockfd);
		return 1;

	}

	char client_text[TEXT_SIZE];
	memset(client_text, 0, sizeof(client_text));

	ssize_t bytes_recv = recv(client_fd, client_text, sizeof(client_text) - 1, 0);

	if(bytes_recv < 0){

		perror("[ERROR] recv error from client");
		close(log_fd);
		close(client_fd);
		close(sockfd);
		return 1;

	}

	client_text[bytes_recv] = '\0';
	printf("[SERVER] -> Log entry received from client: \"%s\"\n", client_text);

	char formatted_entry[TEXT_SIZE + 64];
	int entry_len = snprintf(formatted_entry, sizeof(formatted_entry),
	                         "[LOG_RECEIVED] %s\n", client_text);

	if(entry_len > 0 && (size_t)entry_len < sizeof(formatted_entry)){

		if(write(log_fd, formatted_entry, (size_t)entry_len) < 0){

			perror("[ERROR] Failed to write log entry to file");

		}else{

			printf("[SERVER] -> Appended to '%s'.\n", log_path);

		}

	}

	const char ack_msg[] = "\n~Saved~\n";
	if(send(client_fd, ack_msg, sizeof(ack_msg) - 1, 0) < 0){

		perror("[ERROR] Failed to send acknowledgment");

	}

	close(log_fd);
	close(client_fd);
	close(sockfd);

	printf("[SERVER] -> Connection handled and closed cleanly.\n");

	return 0;

}
