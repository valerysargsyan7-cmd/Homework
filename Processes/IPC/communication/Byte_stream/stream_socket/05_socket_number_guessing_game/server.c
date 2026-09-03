#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define TEXT_SIZE 5000
#define MAX_CONNECT 5

int main()
{

	printf("\n============================================\n");
	printf("||     NUMBER GUESSING SOCKET SERVER      ||\n");
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

	int secret = 42;
	printf("Game server online (Secret number: %d).\nListening on port %d...\n", secret, PORT);

	int client_fd = accept(sockfd, (struct sockaddr *)&client, &client_size);

	if(client_fd < 0){

		perror("[ERROR] Accept connection failed");
		close(sockfd);
		return 1;

	}

	printf("\n[SUCCESS] Player connected! (IP: %s, Port: %d)\n",
	       inet_ntoa(client.sin_addr), ntohs(client.sin_port));

	int attempts = 0;

	while(1){

		char client_text[TEXT_SIZE];
		memset(client_text, 0, sizeof(client_text));

		ssize_t bytes_recv = recv(client_fd, client_text, sizeof(client_text) - 1, 0);

		if(bytes_recv <= 0){

			printf("\n[INFO] Client disconnected or connection lost.\n");
			break;

		}

		client_text[bytes_recv] = '\0';
		int guess = atoi(client_text);
		attempts++;

		printf("[GAME] -> Attempt %d: Player guessed %d\n", attempts, guess);

		if(guess < secret){

			if(send(client_fd, "Higher", strlen("Higher") + 1, 0) < 0){

				perror("[ERROR] send response failed");
				break;

			}

		}else if(guess > secret){

			if(send(client_fd, "Lower", strlen("Lower") + 1, 0) < 0){

				perror("[ERROR] send response failed");
				break;

			}

		}else{

			if(send(client_fd, "Correct", strlen("Correct") + 1, 0) < 0){

				perror("[ERROR] send response failed");
				break;

			}

			printf("[GAME] -> Player guessed correctly in %d attempts! Game over.\n", attempts);
			break;

		}

	}

	close(client_fd);
	close(sockfd);

	return 0;

}
