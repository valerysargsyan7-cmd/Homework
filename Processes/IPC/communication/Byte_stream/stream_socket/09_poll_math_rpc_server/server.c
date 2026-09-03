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

int main()
{

	printf("\n============================================\n");
	printf("||       POLL MATH RPC SOCKET SERVER      ||\n");
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
	memset(fds, 0, sizeof(fds));

	fds[0].fd = sockfd;
	fds[0].events = POLLIN;

	int nfds = 1;

	printf("Math RPC Server listening on port %d... (Commands: ADD, SUB, MUL)\n", PORT);

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

						printf("[WARNING] Server busy. Rejecting client.\n");
						close(client_fd);
						continue;

					}

					fds[nfds].fd = client_fd;
					fds[nfds].events = POLLIN;
					nfds++;

					printf("\n[CONNECT] Client connected (FD: %d, IP: %s)\n",
					       client_fd, inet_ntoa(client.sin_addr));

				}else{

					char client_text[TEXT_SIZE];
					memset(client_text, 0, sizeof(client_text));

					ssize_t bytes_recv = recv(fds[i].fd, client_text, sizeof(client_text) - 1, 0);

					if(bytes_recv <= 0){

						printf("[DISCONNECT] Client on FD %d closed connection.\n", fds[i].fd);
						close(fds[i].fd);

						fds[i] = fds[nfds - 1];
						nfds--;
						i--;
						continue;

					}

					client_text[bytes_recv] = '\0';
					printf("[RPC] -> Request from FD %d: \"%s\"\n", fds[i].fd, client_text);

					char op[16];
					int num1 = 0;
					int num2 = 0;

					int parsed = sscanf(client_text, "%15s %d %d", op, &num1, &num2);

					if(parsed != 3){

						const char err_msg[] = "ERROR: Invalid command syntax. Use: <ADD|SUB|MUL> <num1> <num2>\n";
						send(fds[i].fd, err_msg, sizeof(err_msg) - 1, 0);
						continue;

					}

					char resp[128];
					int resp_len = 0;

					if(strcmp(op, "ADD") == 0){

						int result = num1 + num2;
						resp_len = snprintf(resp, sizeof(resp), "Result: %d\n", result);

					}else if(strcmp(op, "SUB") == 0){

						int result = num1 - num2;
						resp_len = snprintf(resp, sizeof(resp), "Result: %d\n", result);

					}else if(strcmp(op, "MUL") == 0){

						int result = num1 * num2;
						resp_len = snprintf(resp, sizeof(resp), "Result: %d\n", result);

					}else{

						resp_len = snprintf(resp, sizeof(resp), "ERROR: Unknown operation '%s'\n", op);

					}

					if(resp_len > 0 && (size_t)resp_len < sizeof(resp)){

						if(send(fds[i].fd, resp, (size_t)resp_len, 0) < 0){

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
