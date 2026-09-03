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
	printf("||     POLL TIMEOUT SOCKET CLIENT         ||\n");
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

	printf("Connecting to Timeout Server at %s:%d...\n", IP, PORT);

	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){

		perror("[ERROR] Connection to server failed");
		close(sockfd);
		return 1;

	}

	printf("[SUCCESS] Connected to Timeout Server!\n\n");

	const char payload[] = "Network socket timeout testing message payload.";

	printf("[CLIENT] -> Sending test payload:\n  \"%s\"\n\n", payload);

	if(send(sockfd, payload, strlen(payload) + 1, 0) < 0){

		perror("[ERROR] send payload failed");
		close(sockfd);
		return 1;

	}

	char server_recv[TEXT_SIZE];
	memset(server_recv, 0, sizeof(server_recv));

	ssize_t bytes_recv = recv(sockfd, server_recv, sizeof(server_recv) - 1, 0);

	if(bytes_recv < 0){

		perror("[ERROR] recv response failed");
		close(sockfd);
		return 1;

	}

	server_recv[bytes_recv] = '\0';
	printf("[RESPONSE FROM SERVER] -> %s\n", server_recv);

	close(sockfd);
	return 0;

}
