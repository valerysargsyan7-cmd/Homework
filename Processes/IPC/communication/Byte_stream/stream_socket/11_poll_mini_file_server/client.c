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
	printf("||      POLL MINI FILE SOCKET CLIENT      ||\n");
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

	printf("Connecting to File Server at %s:%d...\n", IP, PORT);

	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){

		perror("[ERROR] Connection to file server failed");
		close(sockfd);
		return 1;

	}

	printf("[SUCCESS] Connected to File Server! (Try: 'sample_doc.txt', 'empty_doc.txt', 'unknown.txt')\n\n");

	while(1){

		char filename[256];
		memset(filename, 0, sizeof(filename));

		printf("Enter file name to fetch (or 'exit'): ");

		if(scanf("%255s", filename) != 1){

			break;

		}

		if(strcmp(filename, "exit") == 0){

			printf("Closing connection...\n");
			break;

		}

		if(send(sockfd, filename, strlen(filename) + 1, 0) < 0){

			perror("[ERROR] send file request failed");
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
		printf("\n====[ FILE RESPONSE ]====\n%s=========================\n\n", server_recv);

	}

	close(sockfd);
	return 0;

}
