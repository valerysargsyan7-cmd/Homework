# Child Execution Timeout (Watchdog)
A C program demonstrating a process watchdog pattern using `alarm()` and `SIGALRM` to enforce execution time limits on child processes.
## Description
This program demonstrates how a parent process can enforce a maximum execution duration for an untrusted or long-running child task. The child launches a 10-second command (`sleep 10`) via `execlp()`. The parent registers a `SIGALRM` signal handler and arms a 3-second alarm using `alarm(3)`. When 3 seconds elapse, the handler triggers, forcefully terminating the child with `kill(child_pid, SIGKILL)` and avoiding unbounded execution.
## Features
- Child process execution with `fork()` and `execlp()`.
- Watchdog timer implementation using POSIX `alarm(3)` and `SIGALRM`.
- Forceful termination of timed-out processes using `kill()` with `SIGKILL`.
- Inspection of signal termination using `WIFSIGNALED` and `WTERMSIG`.
- Standard C17 and POSIX compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system with `sleep` available on `PATH`
## Building
To compile the project, run:
```bash
make
```
To clean up built binaries:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./child_execution_timeout
```
## Usage Examples
**Watchdog Timeout Output Example:**
```text


Child Execution Timeout (Watchdog)

[CHILD] -> Starting task (sleep 10)...
[PARENT] -> Started child PID 18230. Setting alarm for 3 seconds...

[WATCHDOG] -> Child process exceeded time limit and was killed
[PARENT] -> Child was terminated by signal: 9
[PARENT] -> Watchdog monitoring finished.
```
