// 1
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
int main()
{
    int fd = open("file.txt", O_RDONLY);
    dup2(fd, STDIN_FILENO);

    close(fd);
    char line[100];
    fgets(line, sizeof(line), stdin);
    printf("Read from file: %s", line);
    return 0;
}
// 2
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
int main()
{
    int fd = open("app.log",
                  O_WRONLY | O_CREAT | O_TRUNC,
                  0644);
    dup2(fd, STDOUT_FILENO);
    dup2(fd, STDERR_FILENO);
    close(fd);
    char line[100];
    fgets(line, sizeof(line), stdin);
    printf("Read from file: %s", line);
    return 0;
}
// 3
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int saved_stdout = dup(STDOUT_FILENO);
    if (saved_stdout == -1)
    {
        perror("dup");
        return 1;
    }
    int fd = open("temp.txt",
                  O_WRONLY | O_CREAT | O_TRUNC,
                  0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    printf("Տպում ենք ֆայլի մեջ.\n");
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    printf("Վերադարձանք էկրանին.\n");

    return 0;
}
// 4
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd[2];
    int pipe(fd);
    pid_t pid = fork();
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("ls", "ls", NULL);
    }
    else
    {
        close(fd[1]);

        dup2(fd[0], STDIN_FILENO);

        close(fd[0]);

        execlp("wc", "wc", "-l", NULL);
    }
    return 0;
}
// 5
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int input_fd = open("input.log", O_RDONLY);
    if (input_fd == -1)
    {
        perror("open input.log");
        return 1;
    }
    int output_fd = open("errors.txt",
                         O_WRONLY | O_CREAT | O_TRUNC,
                         0644);

    if (output_fd == -1)
    {
        perror("open errors.txt");
        return 1;
    }
    dup2(input_fd, STDIN_FILENO);

    dup2(output_fd, STDOUT_FILENO);

    close(input_fd);
    close(output_fd);

    execlp("grep", "grep", "error", NULL);

    perror("execlp");
    return 1;
}
// 6
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);  
    pid_t pid1 = fork();

    if (pid1 == 0)
    {
        close(fd1[0]);
        dup2(fd1[1], STDOUT_FILENO);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("cat", "cat", "data.txt", NULL);
        perror("cat");
        exit(1);
    }
    else
    {
        pid_t pid2 = fork();

        if (pid2 == 0)
        {
            close(fd1[1]);
            dup2(fd1[0], STDIN_FILENO);
            close(fd2[0]);
            dup2(fd2[1], STDOUT_FILENO);
            close(fd1[0]);
            close(fd2[1]);
            execlp("grep", "grep", "A", NULL);
            perror("grep");
            exit(1);
        }
        else
        {
            close(fd1[0]);
            close(fd1[1]);
            close(fd2[1]);
            dup2(fd2[0], STDIN_FILENO);
            close(fd2[0]);
            execlp("sort", "sort", NULL);
            perror("sort");
            exit(1);
        }
    }

    return 0;
}
