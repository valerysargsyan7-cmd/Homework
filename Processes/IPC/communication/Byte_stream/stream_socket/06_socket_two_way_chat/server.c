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
	printf("||       TWO-WAY CHAT SOCKET SERVER       ||\n");
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

	printf("Chat server online. Listening on port %d... Waiting for peer...\n", PORT);

	int client_fd = accept(sockfd, (struct sockaddr *)&client, &client_size);

	if(client_fd < 0){

		perror("[ERROR] Accept connection failed");
		close(sockfd);
		return 1;

	}

	printf("\n[SUCCESS] Peer connected! (IP: %s, Port: %d)\n",
	       inet_ntoa(client.sin_addr), ntohs(client.sin_port));
	printf("Type 'exit' to conclude the chat session.\n\n");

	while(1){

		char client_recv[TEXT_SIZE];
		memset(client_recv, 0, sizeof(client_recv));

		ssize_t bytes_recv = recv(client_fd, client_recv, sizeof(client_recv) - 1, 0);

		if(bytes_recv <= 0){

			printf("\n[INFO] Client disconnected.\n");
			break;

		}

		client_recv[bytes_recv] = '\0';
		printf("\n[CLIENT] :> %s\n", client_recv);

		if(strcmp(client_recv, "exit") == 0){

			printf("\nClient initiated session close. Exiting chat...\n");
			break;

		}

		char reply_text[TEXT_SIZE];
		memset(reply_text, 0, sizeof(reply_text));

		printf("[SERVER] :> ");
		if(fgets(reply_text, sizeof(reply_text), stdin) == NULL){

			break;

		}

		reply_text[strcspn(reply_text, "\r\n")] = '\0';

		if(send(client_fd, reply_text, strlen(reply_text) + 1, 0) < 0){

			perror("[ERROR] send message failed");
			break;

		}

		if(strcmp(reply_text, "exit") == 0){

			printf("\nClosing chat session...\n");
			break;

		}

	}

	close(client_fd);
	close(sockfd);

	return 0;

}
