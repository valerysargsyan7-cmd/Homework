#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <poll.h>

#define PORT 8080
#define TEXT_SIZE 5000
#define MAX_CONNECT 5

int main()
{

	printf("\n============================================\n");
	printf("||     POLL MULTI-CLIENT WORD COUNTER     ||\n");
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

		perror("[ERROR] Failed to create master socket");
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

	struct pollfd fds[MAX_CONNECT + 1];
	memset(fds, 0, sizeof(fds));

	fds[0].fd = sockfd;
	fds[0].events = POLLIN;

	int nfds = 1;

	printf("Word Counter Server active on port %d with poll() multiplexing.\nWaiting for connections...\n", PORT);

	while(1){

		int poll_ret = poll(fds, (nfds_t)nfds, -1);

		if(poll_ret < 0){

			perror("[ERROR] poll failed");
			break;

		}

		for(int i = 0; i < nfds; i++){

			if(fds[i].revents & POLLIN){

				if(fds[i].fd == sockfd){

					// New incoming client connection
					int client_fd = accept(sockfd, (struct sockaddr *)&client, &client_size);

					if(client_fd < 0){

						perror("[ERROR] Accept connection failed");
						continue;

					}

					if(nfds >= MAX_CONNECT + 1){

						printf("[WARNING] Maximum concurrent connection limit reached (%d). Rejecting client.\n", MAX_CONNECT);
						close(client_fd);
						continue;

					}

					fds[nfds].fd = client_fd;
					fds[nfds].events = POLLIN;
					nfds++;

					printf("\n[CONNECT] New client attached (FD: %d, IP: %s, Port: %d)\n",
					       client_fd, inet_ntoa(client.sin_addr), ntohs(client.sin_port));

				}else{

					// Incoming text from connected client
					char client_text[TEXT_SIZE];
					memset(client_text, 0, sizeof(client_text));

					ssize_t bytes_recv = recv(fds[i].fd, client_text, sizeof(client_text) - 1, 0);

					if(bytes_recv <= 0){

						printf("[DISCONNECT] Client on FD %d disconnected.\n", fds[i].fd);
						close(fds[i].fd);

						// Compact poll array
						fds[i] = fds[nfds - 1];
						nfds--;
						i--;
						continue;

					}

					client_text[bytes_recv] = '\0';
					printf("[SERVER] -> Received text from FD %d (%zd bytes).\n", fds[i].fd, bytes_recv);

					int word_count = 0;
					int in_word = 0;

					for(size_t j = 0; client_text[j] != '\0'; j++){

						if(isspace((unsigned char)client_text[j])){

							in_word = 0;

						}else{

							if(in_word == 0){

								word_count++;

							}

							in_word = 1;

						}

					}

					printf("[SERVER] -> Counted %d words for client on FD %d.\n", word_count, fds[i].fd);

					char response[128];
					int resp_len = snprintf(response, sizeof(response), "Words Count: %d\n", word_count);

					if(resp_len > 0 && (size_t)resp_len < sizeof(response)){

						if(send(fds[i].fd, response, (size_t)resp_len, 0) < 0){

							perror("[ERROR] send response failed");

						}

					}

				}

			}

		}

	}

	for(int i = 0; i < nfds; i++){

		if(fds[i].fd >= 0){

			close(fds[i].fd);

		}

	}

	return 0;

}
