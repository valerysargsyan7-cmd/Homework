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
	printf("||    MULTIPLAYER GUESSER SOCKET CLIENT   ||\n");
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

	printf("Connecting to Multiplayer Game Server at %s:%d...\n", IP, PORT);

	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){

		perror("[ERROR] Connection to game server failed");
		close(sockfd);
		return 1;

	}

	printf("[SUCCESS] Connected to Multiplayer Arena! Guess the secret (1..100):\n\n");

	while(1){

		char text[TEXT_SIZE];
		memset(text, 0, sizeof(text));

		printf("Your guess: ");

		if(fgets(text, sizeof(text), stdin) == NULL){

			break;

		}

		text[strcspn(text, "\r\n")] = '\0';

		if(send(sockfd, text, strlen(text) + 1, 0) < 0){

			perror("[ERROR] send guess failed");
			break;

		}

		char server_recv[TEXT_SIZE];
		memset(server_recv, 0, sizeof(server_recv));

		ssize_t bytes_recv = recv(sockfd, server_recv, sizeof(server_recv) - 1, 0);

		if(bytes_recv <= 0){

			printf("\n[INFO] Game round concluded or server disconnected.\n");
			break;

		}

		server_recv[bytes_recv] = '\0';
		printf("Server Feedback -> %s\n", server_recv);

		if(strstr(server_recv, "YOU WON") != NULL || strstr(server_recv, "GAME OVER") != NULL){

			break;

		}

	}

	close(sockfd);
	return 0;

}
