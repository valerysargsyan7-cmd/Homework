// 1 clinet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080
int main()
{
    int sock;

    struct sockaddr_in server_addr;

    char buffer[100];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        perror("socket");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr =
        inet_addr("127.0.0.1");
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connection fault");
        exit(1);
    }
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, strlen(buffer));
    recv(socket, buffer, strlen(buffer), 0);
    printf("%s", buffer);
    close(sock);
    return 0;
}
// 1 server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void reverse_string(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main()
{
    int server_fd, client_fd;

    struct sockaddr_in server_addr, client_addr;

    socklen_t addr_size = sizeof(client_addr);

    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    listen(server_fd, 5);

    printf("Server waiting on port %d...\n", PORT);

    client_fd = accept(server_fd,
                       (struct sockaddr *)&client_addr,
                       &addr_size);

    if (client_fd < 0)
    {
        perror("accept");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);

    recv(client_fd,
         buffer,
         BUFFER_SIZE,
         0);

    printf("Received: %s\n", buffer);

    reverse_string(buffer);

    send(client_fd,
         buffer,
         strlen(buffer),
         0);

    printf("Sent: %s\n", buffer);

    close(client_fd);
    close(server_fd);

    return 0;
}
// 2 clinet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock;

    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    server_addr.sin_addr.s_addr =
        inet_addr("127.0.0.1");

    if (connect(sock,
                (struct sockaddr *)&server_addr,
                sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    printf("Enter log: ");

    fgets(buffer,
          BUFFER_SIZE,
          stdin);

    buffer[strcspn(buffer, "\n")] = 0;

    send(sock,
         buffer,
         strlen(buffer),
         0);

    memset(buffer, 0, BUFFER_SIZE);

    recv(sock,
         buffer,
         BUFFER_SIZE,
         0);

    printf("Server response: %s\n", buffer);

    close(sock);

    return 0;
}
// 2 server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, client_fd;

    struct sockaddr_in server_addr, client_addr;

    socklen_t addr_size = sizeof(client_addr);

    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    listen(server_fd, 5);

    while (1)
    {
        client_fd = accept(server_fd,
                           (struct sockaddr *)&client_addr,
                           &addr_size);

        if (client_fd < 0)
        {
            perror("accept");
            continue;
        }

        memset(buffer, 0, BUFFER_SIZE);

        recv(client_fd,
             buffer,
             BUFFER_SIZE,
             0);

        FILE *file = fopen("server_logs.txt", "a");

        if (file != NULL)
        {
            fprintf(file,
                    "[LOG_RECEIVED] %s\n",
                    buffer);

            fclose(file);
        }

        char response[] = "Saved";

        send(client_fd,
             response,
             strlen(response),
             0);

        close(client_fd);
    }

    close(server_fd);

    return 0;
}
// 3 clinet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock;

    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    server_addr.sin_addr.s_addr =
        inet_addr("127.0.0.1");

    if (connect(sock,
                (struct sockaddr *)&server_addr,
                sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    printf("TEMP : ");

    fgets(buffer,
          BUFFER_SIZE,
          stdin);

    buffer[strcspn(buffer, "\n")] = '\0';
    send(sock,
         buffer,
         strlen(buffer),
         0);

    memset(buffer, 0, BUFFER_SIZE);

    recv(sock,
         buffer,
         BUFFER_SIZE,
         0);
    printf("Server response: %s\n", buffer);
    clsoe(sock);
    return 0;
}
// 3 server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int get_temperature(char *data)
{
    int temp = 0;

    char *ptr = strchr(data, ':');

    if (ptr != NULL)
    {
        ptr++;

        while (*ptr >= '0' && *ptr <= '9')
        {
            temp = temp * 10 + (*ptr - '0');
            ptr++;
        }
    }

    return temp;
}

int main()
{
    int server_fd, client_fd;

    struct sockaddr_in server_addr, client_addr;

    socklen_t addr_size = sizeof(client_addr);

    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    listen(server_fd, 5);

    printf("IoT Server running...\n");

    while (1)
    {
        client_fd = accept(server_fd,
                           (struct sockaddr *)&client_addr,
                           &addr_size);

        memset(buffer, 0, BUFFER_SIZE);

        recv(client_fd,
             buffer,
             BUFFER_SIZE,
             0);

        int temperature = get_temperature(buffer);

        char response[BUFFER_SIZE];

        if (temperature > 50)
        {
            strcpy(response,
                   "[ALERT] Dangerously high!");
        }
        else
        {
            strcpy(response,
                   "[OK] Temperature normal");
        }

        send(client_fd,
             response,
             strlen(response),
             0);

        close(client_fd);
    }

    close(server_fd);

    return 0;
}
// 4 client
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 2048

int main()
{
    int sock;

    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET,
                  SOCK_STREAM,
                  0);

    if (sock < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    server_addr.sin_addr.s_addr =
        inet_addr("127.0.0.1");

    if (connect(sock,
                (struct sockaddr *)&server_addr,
                sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    printf("Enter a long sentence:\n");

    fgets(buffer,
          BUFFER_SIZE,
          stdin);

    buffer[strcspn(buffer, "\n")] = '\0';

    send(sock,
         buffer,
         strlen(buffer),
         0);

    memset(buffer, 0, BUFFER_SIZE);

    recv(sock,
         buffer,
         BUFFER_SIZE,
         0);

    printf("Server response: %s\n",
           buffer);

    close(sock);

    return 0;
}
// 4 server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 2048

int count_vowels(char *text)
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int server_fd, client_fd;

    struct sockaddr_in server_addr, client_addr;

    socklen_t addr_size = sizeof(client_addr);

    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    listen(server_fd, 5);

    printf("Server waiting...\n");

    client_fd = accept(server_fd,
                       (struct sockaddr *)&client_addr,
                       &addr_size);

    memset(buffer, 0, BUFFER_SIZE);

    recv(client_fd,
         buffer,
         BUFFER_SIZE,
         0);

    int result = count_vowels(buffer);

    char response[100];

    sprintf(response,
            "Vowels count: %d",
            result);

    send(client_fd,
         response,
         strlen(response),
         0);

    close(client_fd);
    close(server_fd);

    return 0;
}
// 5 client
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 2048

int main()
{
    int sock;

    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET,
                  SOCK_STREAM,
                  0);

    if (sock < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    server_addr.sin_addr.s_addr =
        inet_addr("127.0.0.1");

    if (connect(sock,
                (struct sockaddr *)&server_addr,
                sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    while (1)
    {
        printf("Enter a long sentence:\n");
        fgets(buffer,
              BUFFER_SIZE,
              stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        send(sock,
             buffer,
             strlen(buffer),
             0);

        memset(buffer, 0, BUFFER_SIZE);

        recv(sock,
             buffer,
             BUFFER_SIZE,
             0);
        printf("Server response: %s\n",
               buffer);
    }

    close(sock);

    return 0;
}
// 5 server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, client_fd;

    struct sockaddr_in server_addr, client_addr;

    socklen_t addr_size = sizeof(client_addr);

    char buffer[BUFFER_SIZE];

    int secret = 42;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    listen(server_fd, 5);

    printf("Guess server waiting...\n");

    client_fd = accept(server_fd,
                       (struct sockaddr *)&client_addr,
                       &addr_size);

    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);

        recv(client_fd,
             buffer,
             BUFFER_SIZE,
             0);

        int guess = atoi(buffer);

        char response[50];

        if (guess > secret)
        {
            strcpy(response, "Lower");
        }
        else if (guess < secret)
        {
            strcpy(response, "Higher");
        }
        else
        {
            strcpy(response, "Correct");
        }

        send(client_fd,
             response,
             strlen(response),
             0);

        if (guess == secret)
        {
            break;
        }
    }

    close(client_fd);
    close(server_fd);

    return 0;
}
// 6