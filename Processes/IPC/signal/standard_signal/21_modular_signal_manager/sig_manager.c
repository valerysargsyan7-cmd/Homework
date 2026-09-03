#include <stdio.h>
#include <signal.h>

#include "sig_manager.h"

void register_safe_handler(int sig, void (*handler)(int))
{

	if(signal(sig, handler) == SIG_ERR){

		perror("[ERROR] Failed to register signal handler");

	}

}
