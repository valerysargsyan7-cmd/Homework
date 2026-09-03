#ifndef SIG_MANAGER_H
#define SIG_MANAGER_H

void register_safe_handler(int sig, void (*handler)(int));

#endif
