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
	printf("||     WORD COUNTER SOCKET CLIENT         ||\n");
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

	printf("Connecting to Word Counter Server at %s:%d...\n", IP, PORT);

	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){

		perror("[ERROR] Connection to server failed");
		close(sockfd);
		return 1;

	}

	printf("[SUCCESS] Connected to Word Counter Server!\n\n");

	const char sample_text[] =
		"Operating system multiplexing with poll enables high performance "
		"concurrent network servers without spawning threads or processes.";

	printf("[CLIENT] -> Transmitting text string for word analysis:\n  \"%s\"\n\n", sample_text);

	if(send(sockfd, sample_text, strlen(sample_text) + 1, 0) < 0){

		perror("[ERROR] send text failed");
		close(sockfd);
		return 1;

	}

	char server_recv[TEXT_SIZE];
	memset(server_recv, 0, sizeof(server_recv));

	ssize_t bytes_recv = recv(sockfd, server_recv, sizeof(server_recv) - 1, 0);

	if(bytes_recv < 0){

		perror("[ERROR] recv response from server failed");
		close(sockfd);
		return 1;

	}

	server_recv[bytes_recv] = '\0';
	printf("[ANALYSIS RESULT] -> %s\n", server_recv);

	close(sockfd);
	return 0;

}
