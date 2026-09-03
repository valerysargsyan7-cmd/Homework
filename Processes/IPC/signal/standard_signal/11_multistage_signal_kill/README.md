# Multistage Signal Delivery and Kill
A C program demonstrating sequenced inter-process signaling: notifying a child process with `SIGUSR1`, followed by mandatory termination via `SIGKILL` and status reporting.
## Description
This program demonstrates multi-phase signal interaction between a parent and child process. The child sets up a signal handler for `SIGUSR1` and enters a processing loop. The parent sequence is as follows:
1. Sleeps for 2 seconds and transmits `SIGUSR1` to the child using `kill()`.
2. The child catches `SIGUSR1`, sets a flag, and outputs a notification.
3. The parent sleeps for another 2 seconds and dispatches `SIGKILL` to forcefully terminate the child.
4. The parent reaps the child using `wait(&status)` and inspects `WIFSIGNALED()` and `WTERMSIG()` to confirm termination via signal 9 (`SIGKILL`).
## Features
- Process creation and background execution with `fork()`.
- Multi-phase signal dispatching using `kill()`.
- Signal handling for `SIGUSR1` with deferred safe output.
- Unconditional child termination via `SIGKILL`.
- Signal termination inspection using `WIFSIGNALED` and `WTERMSIG`.
- Standard C17 and POSIX compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS)
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
./multistage_signal_kill
```
## Usage Examples
**Multistage Signal Delivery Output Example:**
```text


Multistage Signal Delivery & Kill

[CHILD] -> Running and waiting for signals...

[PARENT] -> Sending SIGUSR1 to child...

[HANDLER] -> Child received USR1 signal!
[PARENT] -> Sending SIGKILL to child...

[PARENT] -> Child was terminated by signal: 9
[PARENT] -> Program finished.
```
