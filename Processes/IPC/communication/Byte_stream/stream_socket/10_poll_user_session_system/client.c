#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define TEXT_SIZE 5000
#define IP "127.0.0.1"

int main()
{

	printf("\n============================================\n");
	printf("||     POLL USER SESSION SOCKET CLIENT    ||\n");
	printf("============================================\n\n");

	struct sockaddr_in server;
	memset(&server, 0, sizeof(server));

	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);

	if(inet_pton(AF_INET, IP, &server.sin_addr.s_addr) <= 0){

		perror("[ERROR] Invalid server IP address");
		return 1;

	}

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0){

		perror("[ERROR] Failed to create socket");
		return 1;

	}

	printf("Connecting to User Session Server at %s:%d...\n", IP, PORT);

	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){

		perror("[ERROR] Connection to server failed");
		close(sockfd);
		return 1;

	}

	printf("[SUCCESS] Connected to Server!\n\n");

	// Step 1: Prompt for username registration
	char username[TEXT_SIZE];
	memset(username, 0, sizeof(username));

	printf("Enter your username to register: ");
	if(fgets(username, sizeof(username), stdin) == NULL){

		close(sockfd);
		return 1;

	}

	username[strcspn(username, "\r\n")] = '\0';

	if(send(sockfd, username, strlen(username) + 1, 0) < 0){

		perror("[ERROR] Failed to send username");
		close(sockfd);
		return 1;

	}

	char server_recv[TEXT_SIZE];
	memset(server_recv, 0, sizeof(server_recv));

	ssize_t bytes_recv = recv(sockfd, server_recv, sizeof(server_recv) - 1, 0);

	if(bytes_recv <= 0){

		printf("[ERROR] Server disconnected.\n");
		close(sockfd);
		return 1;

	}

	server_recv[bytes_recv] = '\0';
	printf("Server: %s\n", server_recv);

	// Step 2: Message loop
	while(1){

		char message[TEXT_SIZE];
		memset(message, 0, sizeof(message));

		printf("Message (or 'exit'): ");

		if(fgets(message, sizeof(message), stdin) == NULL){

			break;

		}

		message[strcspn(message, "\r\n")] = '\0';

		if(strcmp(message, "exit") == 0){

			printf("Closing session...\n");
			break;

		}

		if(strlen(message) == 0){

			continue;

		}

		if(send(sockfd, message, strlen(message) + 1, 0) < 0){

			perror("[ERROR] send message failed");
			break;

		}

		memset(server_recv, 0, sizeof(server_recv));
		bytes_recv = recv(sockfd, server_recv, sizeof(server_recv) - 1, 0);

		if(bytes_recv <= 0){

			printf("[INFO] Server closed the connection.\n");
			break;

		}

		server_recv[bytes_recv] = '\0';
		printf("Server: %s\n", server_recv);

	}

	close(sockfd);
	return 0;

}
