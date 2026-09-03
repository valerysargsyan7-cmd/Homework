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
	printf("||       POLL MATH RPC SOCKET CLIENT      ||\n");
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

	printf("Connecting to Math RPC Server at %s:%d...\n", IP, PORT);

	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){

		perror("[ERROR] Connection to server failed");
		close(sockfd);
		return 1;

	}

	printf("[SUCCESS] Connected to Math RPC Server! Examples: 'ADD 10 20', 'SUB 50 15', 'MUL 6 7'\n\n");

	while(1){

		char command[TEXT_SIZE];
		memset(command, 0, sizeof(command));

		printf("RPC Command (or 'exit'): ");

		if(fgets(command, sizeof(command), stdin) == NULL){

			break;

		}

		command[strcspn(command, "\r\n")] = '\0';

		if(strcmp(command, "exit") == 0){

			printf("Closing connection...\n");
			break;

		}

		if(strlen(command) == 0){

			continue;

		}

		if(send(sockfd, command, strlen(command) + 1, 0) < 0){

			perror("[ERROR] send command failed");
			break;

		}

		char server_recv[TEXT_SIZE];
		memset(server_recv, 0, sizeof(server_recv));

		ssize_t bytes_recv = recv(sockfd, server_recv, sizeof(server_recv) - 1, 0);

		if(bytes_recv <= 0){

			printf("[INFO] Server closed the connection.\n");
			break;

		}

		server_recv[bytes_recv] = '\0';
		printf("Server -> %s\n", server_recv);

	}

	close(sockfd);
	return 0;

}
