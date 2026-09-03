#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <poll.h>

#define PORT 8080
#define TEXT_SIZE 5000
#define MAX_CONNECT 5

struct ClientInfo {
	int fd;
	char name[50];
};

int main()
{

	printf("\n============================================\n");
	printf("||     POLL USER SESSION SYSTEM SERVER    ||\n");
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

	struct pollfd fds[MAX_CONNECT + 1];
	struct ClientInfo clients[MAX_CONNECT + 1];

	memset(fds, 0, sizeof(fds));
	memset(clients, 0, sizeof(clients));

	fds[0].fd = sockfd;
	fds[0].events = POLLIN;

	int nfds = 1;

	printf("User Session Server listening on port %d... Waiting for clients...\n", PORT);

	while(1){

		int poll_ret = poll(fds, (nfds_t)nfds, -1);

		if(poll_ret < 0){

			perror("[ERROR] poll failed");
			break;

		}

		for(int i = 0; i < nfds; i++){

			if(fds[i].revents & POLLIN){

				if(fds[i].fd == sockfd){

					int client_fd = accept(sockfd, (struct sockaddr *)&client, &client_size);

					if(client_fd < 0){

						perror("[ERROR] Accept connection failed");
						continue;

					}

					if(nfds >= MAX_CONNECT + 1){

						printf("[WARNING] Connection pool full. Rejecting client.\n");
						close(client_fd);
						continue;

					}

					fds[nfds].fd = client_fd;
					fds[nfds].events = POLLIN;
					clients[nfds].fd = client_fd;
					clients[nfds].name[0] = '\0';
					nfds++;

					printf("\n[CONNECT] New client socket attached (FD: %d)\n", client_fd);

				}else{

					char client_text[TEXT_SIZE];
					memset(client_text, 0, sizeof(client_text));

					ssize_t bytes_recv = recv(fds[i].fd, client_text, sizeof(client_text) - 1, 0);

					if(bytes_recv <= 0){

						if(strlen(clients[i].name) > 0){

							printf("[DISCONNECT] User '%s' (FD %d) disconnected.\n",
							       clients[i].name, fds[i].fd);

						}else{

							printf("[DISCONNECT] Unregistered client on FD %d disconnected.\n",
							       fds[i].fd);

						}

						close(fds[i].fd);

						// Compact both arrays
						fds[i] = fds[nfds - 1];
						clients[i] = clients[nfds - 1];
						nfds--;
						i--;
						continue;

					}

					client_text[bytes_recv] = '\0';

					if(strlen(clients[i].name) == 0){

						// First message is user registration
						strncpy(clients[i].name, client_text, sizeof(clients[i].name) - 1);
						clients[i].name[sizeof(clients[i].name) - 1] = '\0';

						printf("[REGISTER] FD %d registered as username: '%s'\n",
						       fds[i].fd, clients[i].name);

						char welcome_msg[128];
						int w_len = snprintf(welcome_msg, sizeof(welcome_msg),
						                    "Welcome %s! You are registered. You can now send messages.\n",
						                    clients[i].name);

						if(w_len > 0 && (size_t)w_len < sizeof(welcome_msg)){

							send(fds[i].fd, welcome_msg, (size_t)w_len, 0);

						}

					}else{

						// Subsequent messages from registered user
						printf("\n[CHAT] '%s' (FD %d) says: \"%s\"\n",
						       clients[i].name, fds[i].fd, client_text);

						const char ack[] = "Message received!\n";
						send(fds[i].fd, ack, sizeof(ack) - 1, 0);

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
