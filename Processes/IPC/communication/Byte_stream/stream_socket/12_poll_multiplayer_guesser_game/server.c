#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
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
	printf("||    POLL MULTIPLAYER GUESSER SERVER     ||\n");
	printf("============================================\n\n");

	srand((unsigned int)time(NULL));

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
	int random_number = (rand() % 100) + 1;

	printf("Multiplayer Game Server active on port %d.\nSecret target number generated: %d\nWaiting for players...\n",
	       PORT, random_number);

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

						printf("[WARNING] Game room full. Rejecting player.\n");
						close(client_fd);
						continue;

					}

					fds[nfds].fd = client_fd;
					fds[nfds].events = POLLIN;
					nfds++;

					printf("\n[PLAYER JOINED] FD %d entered the game room (IP: %s)\n",
					       client_fd, inet_ntoa(client.sin_addr));

				}else{

					char client_text[TEXT_SIZE];
					memset(client_text, 0, sizeof(client_text));

					ssize_t bytes_recv = recv(fds[i].fd, client_text, sizeof(client_text) - 1, 0);

					if(bytes_recv <= 0){

						printf("[PLAYER LEFT] FD %d disconnected.\n", fds[i].fd);
						close(fds[i].fd);

						fds[i] = fds[nfds - 1];
						nfds--;
						i--;
						continue;

					}

					client_text[bytes_recv] = '\0';
					int guess = atoi(client_text);

					printf("[GAME ACTION] -> FD %d guessed: %d (Secret: %d)\n", fds[i].fd, guess, random_number);

					if(guess == random_number){

						printf("\n[GAME WINNER] -> FD %d guessed correctly (%d)! Broadcasting game over...\n",
						       fds[i].fd, random_number);

						const char win_msg[] = "\n*** YOU WON! CONGRATULATIONS! ***\n";
						send(fds[i].fd, win_msg, sizeof(win_msg) - 1, 0);

						const char lose_msg[] = "\nGAME OVER: Another player guessed the correct number first!\n";

						for(int j = 1; j < nfds; j++){

							if(j != i){

								send(fds[j].fd, lose_msg, sizeof(lose_msg) - 1, 0);
								close(fds[j].fd);

							}

						}

						close(fds[i].fd);

						nfds = 1;
						random_number = (rand() % 100) + 1;
						printf("\n--- Round Reset --- New secret generated (%d). Waiting for players...\n", random_number);
						break;

					}else if(guess > random_number){

						const char lower_msg[] = "LOWER!\n";
						send(fds[i].fd, lower_msg, sizeof(lower_msg) - 1, 0);

					}else{

						const char higher_msg[] = "HIGHER!\n";
						send(fds[i].fd, higher_msg, sizeof(higher_msg) - 1, 0);

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
