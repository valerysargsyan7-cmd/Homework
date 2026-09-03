#ifndef PROC_UTILS_H
#define PROC_UTILS_H

#include <sys/types.h>

pid_t spawn_task(void (*task_func)(void));

#endif
