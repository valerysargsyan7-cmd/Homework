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
	printf("||     IoT MONITORING SOCKET SERVER       ||\n");
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

	printf("IoT Monitor listening on port %d... Waiting for sensor telemetry...\n", PORT);

	int client_fd = accept(sockfd, (struct sockaddr *)&client, &client_size);

	if(client_fd < 0){

		perror("[ERROR] Accept connection failed");
		close(sockfd);
		return 1;

	}

	printf("\n[SUCCESS] Sensor connected! (IP: %s, Port: %d)\n",
	       inet_ntoa(client.sin_addr), ntohs(client.sin_port));

	char client_text[TEXT_SIZE];
	memset(client_text, 0, sizeof(client_text));

	ssize_t bytes_recv = recv(client_fd, client_text, sizeof(client_text) - 1, 0);

	if(bytes_recv < 0){

		perror("[ERROR] recv from sensor failed");
		close(client_fd);
		close(sockfd);
		return 1;

	}

	client_text[bytes_recv] = '\0';
	printf("[SERVER] -> Telemetry payload received: \"%s\"\n", client_text);

	// Extract integer temperature from text
	char *in_word = client_text;
	int current_number = 0;
	int found_number = 0;

	while(*in_word != '\0'){

		if(isdigit((unsigned char)*in_word)){

			found_number = 1;

			while(isdigit((unsigned char)*in_word)){

				current_number = (current_number * 10) + (*in_word - '0');
				in_word++;

			}

			break;

		}else{

			in_word++;

		}

	}

	if(found_number && current_number > 50){

		printf("[SERVER] -> Parsed Temperature: %d C -> THRESHOLD EXCEEDED (> 50 C)!\n", current_number);
		const char alert_msg[] = "\n[ALERT] Dangerously high temperature detected!\n";

		if(send(client_fd, alert_msg, sizeof(alert_msg) - 1, 0) < 0){

			perror("[ERROR] send alert failed");

		}

	}else{

		printf("[SERVER] -> Parsed Temperature: %d C -> NORMAL RANGE (<= 50 C).\n", current_number);
		const char ok_msg[] = "\n[OK] Temperature within normal operational limits.\n";

		if(send(client_fd, ok_msg, sizeof(ok_msg) - 1, 0) < 0){

			perror("[ERROR] send ok status failed");

		}

	}

	close(client_fd);
	close(sockfd);

	return 0;

}
