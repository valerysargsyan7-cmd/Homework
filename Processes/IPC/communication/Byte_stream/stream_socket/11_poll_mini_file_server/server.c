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
	printf("||      POLL MINI FILE SERVER DAEMON      ||\n");
	printf("============================================\n\n");

	// Create sample files for immediate testing
	FILE *fp1 = fopen("sample_doc.txt", "w");
	if(fp1 != NULL){

		fprintf(fp1, "This is sample_doc.txt retrieved from the Mini File Server!\n");
		fclose(fp1);

	}

	FILE *fp2 = fopen("empty_doc.txt", "w");
	if(fp2 != NULL){

		fclose(fp2);

	}

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

	printf("File Server listening on port %d... Ready to serve files via poll().\n", PORT);

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

						printf("[WARNING] Server capacity full. Rejecting client.\n");
						close(client_fd);
						continue;

					}

					fds[nfds].fd = client_fd;
					fds[nfds].events = POLLIN;
					nfds++;

					printf("\n[CONNECT] File client connected (FD: %d)\n", client_fd);

				}else{

					char client_text[TEXT_SIZE];
					memset(client_text, 0, sizeof(client_text));

					ssize_t bytes_recv = recv(fds[i].fd, client_text, sizeof(client_text) - 1, 0);

					if(bytes_recv <= 0){

						printf("[DISCONNECT] File client on FD %d disconnected.\n", fds[i].fd);
						close(fds[i].fd);

						fds[i] = fds[nfds - 1];
						nfds--;
						i--;
						continue;

					}

					client_text[bytes_recv] = '\0';
					printf("[FILE REQUEST] FD %d requested file: \"%s\"\n", fds[i].fd, client_text);

					FILE *file_fp = fopen(client_text, "r");

					if(file_fp == NULL){

						const char not_found[] = "FILE NOT FOUND!\n";
						send(fds[i].fd, not_found, sizeof(not_found) - 1, 0);
						continue;

					}

					char file_buffer[TEXT_SIZE];
					memset(file_buffer, 0, sizeof(file_buffer));

					size_t read_bytes = fread(file_buffer, 1, sizeof(file_buffer) - 1, file_fp);
					fclose(file_fp);

					if(read_bytes == 0){

						const char empty_msg[] = "FILE EMPTY!\n";
						send(fds[i].fd, empty_msg, sizeof(empty_msg) - 1, 0);
						continue;

					}

					file_buffer[read_bytes] = '\0';

					if(send(fds[i].fd, file_buffer, strlen(file_buffer) + 1, 0) < 0){

						perror("[ERROR] send file payload failed");

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
