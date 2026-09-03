#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "ping_pong.h"

static volatile sig_atomic_t pong_flag = 0;

static void sigusr1_handler(int sig_num)
{
	(void)sig_num;
	pong_flag = 1;
}

void wait_ping(void)
{

	if(signal(SIGUSR1, sigusr1_handler) == SIG_ERR){

		perror("[ERROR] signal registration failed");
		exit(1);

	}

	printf("[CHILD] -> Waiting for signal ping from parent...\n");

	while(!pong_flag){

		pause();

	}

	printf("[CHILD] -> Signal ping received! (Pong returned).\n");

}

void send_ping(pid_t target)
{

	if(kill(target, SIGUSR1) == -1){

		perror("[ERROR] kill failed in send_ping");

	}

}
