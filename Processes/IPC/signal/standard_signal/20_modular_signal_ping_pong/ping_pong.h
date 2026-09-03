#ifndef PING_PONG_H
#define PING_PONG_H

#include <sys/types.h>

void wait_ping(void);
void send_ping(pid_t target);

#endif
