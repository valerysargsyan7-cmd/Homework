#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define TEXT_SIZE 5000
#define IP "127.0.0.1"

int main()
{

	printf("\n============================================\n");
	printf("||     IoT SENSOR TELEMETRY CLIENT        ||\n");
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

	printf("Connecting to IoT Monitor at %s:%d...\n", IP, PORT);

	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){

		perror("[ERROR] Connection to IoT monitor failed");
		close(sockfd);
		return 1;

	}

	printf("[SUCCESS] Connected to IoT Monitor!\n\n");

	srand((unsigned int)time(NULL));
	int temperature = (rand() % 91) + 10; // Random reading between 10 and 100 C

	char buffer[1024];
	int prefix_len = snprintf(buffer, sizeof(buffer), "TEMP : %d\n", temperature);

	printf("[SENSOR] -> Reading current hardware sensor: %d C\n", temperature);
	printf("[SENSOR] -> Transmitting telemetry: \"%s\"\n", buffer);

	if(prefix_len > 0 && (size_t)prefix_len < sizeof(buffer)){

		if(send(sockfd, buffer, strlen(buffer) + 1, 0) < 0){

			perror("[ERROR] Failed to transmit telemetry");
			close(sockfd);
			return 1;

		}

	}

	char server_recv[TEXT_SIZE];
	memset(server_recv, 0, sizeof(server_recv));

	ssize_t bytes_recv = recv(sockfd, server_recv, sizeof(server_recv) - 1, 0);

	if(bytes_recv < 0){

		perror("[ERROR] Failed to receive monitor status");
		close(sockfd);
		return 1;

	}

	server_recv[bytes_recv] = '\0';
	printf("Server Monitor Response:%s\n", server_recv);

	close(sockfd);
	return 0;

}
