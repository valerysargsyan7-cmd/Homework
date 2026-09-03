#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    printf("\n\nBlocking Signal\n\n");

    sigset_t signal_set;

    if (sigemptyset(&signal_set) == -1) {

        perror("[ERROR] sigemptyset failed");
        return 1;

    }

    if (sigaddset(&signal_set, SIGINT) == -1) {

        perror("[ERROR] sigaddset failed");
        return 1;

    }

    if (sigprocmask(SIG_BLOCK, &signal_set, NULL) == -1) {

        perror("[ERROR] sigprocmask failed");
        return 1;

    }

    printf("\nSIGINT is blocked for 6 seconds.\n");

    printf("Try pressing Ctrl+C.\n");

    sleep(6);

    printf("\n6 seconds finished.\n");
    
    printf("Program is ending.\n");

    return 0;
}

