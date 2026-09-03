#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define TEXT_SIZE 5000
#define MAX_CONNECT 5

int main()
{

	printf("\n============================================\n");
	printf("||      VOWEL COUNTER SOCKET SERVER       ||\n");
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

	printf("Vowel Counter Server listening on port %d... Waiting for client...\n", PORT);

	int client_fd = accept(sockfd, (struct sockaddr *)&client, &client_size);

	if(client_fd < 0){

		perror("[ERROR] Accept connection failed");
		close(sockfd);
		return 1;

	}

	printf("\n[SUCCESS] Client connected! (IP: %s, Port: %d)\n",
	       inet_ntoa(client.sin_addr), ntohs(client.sin_port));

	char client_text[TEXT_SIZE];
	memset(client_text, 0, sizeof(client_text));

	ssize_t bytes_recv = recv(client_fd, client_text, sizeof(client_text) - 1, 0);

	if(bytes_recv < 0){

		perror("[ERROR] recv error from client");
		close(client_fd);
		close(sockfd);
		return 1;

	}

	client_text[bytes_recv] = '\0';
	printf("[SERVER] -> Received text passage (%zd bytes).\n", bytes_recv);

	int vowel_counter = 0;
	size_t text_len = strlen(client_text);

	for(size_t i = 0; i < text_len; i++){

		char ch = (char)tolower((unsigned char)client_text[i]);

		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){

			vowel_counter++;

		}

	}

	printf("[SERVER] -> Total vowels counted: %d\n", vowel_counter);

	char response_buffer[1024];
	int resp_len = snprintf(response_buffer, sizeof(response_buffer),
	                        "Vowels Count: %d\n", vowel_counter);

	if(resp_len > 0 && (size_t)resp_len < sizeof(response_buffer)){

		if(send(client_fd, response_buffer, (size_t)resp_len + 1, 0) < 0){

			perror("[ERROR] send vowel count failed");

		}

	}

	close(client_fd);
	close(sockfd);

	printf("[SERVER] -> Response dispatched and connection closed.\n");

	return 0;

}
