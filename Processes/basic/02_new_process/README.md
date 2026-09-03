# New Process
A C program demonstrating the POSIX `fork()` system call to create a child process and distinguish parent from child based on the return value.
## Description
This program calls `fork()` to create a new child process. Based on the return value — negative on failure, `0` in the child, and the child's PID in the parent — it prints a different message identifying which process (parent or child) is running, along with that process's own PID.
## Features
- Process duplication via the POSIX `fork()` system call.
- Branching on `fork()`'s return value to distinguish parent, child, and failure cases.
- Error reporting via `perror()` if `fork()` fails.
- Retrieval of each process's own PID via `getpid()`.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS), since this program uses `<unistd.h>` and `fork()`
## Building
To compile the project, run:
```bash
make
```
To clean up built binaries:
```bash
make clean
```
Note: `pid_t` requires `_POSIX_C_SOURCE` to be defined to be visible under strict `-std=c17`; the Makefile sets this via `-D_POSIX_C_SOURCE=200809L`.
## Running
Run the compiled executable:
```bash
./new_process
```
## Usage Examples
**New Process Example:**
```text


New Process


[CHILD] -> Hello I am the Child process!
Child PID: 485


New Process


[PARENT] -> Hello I am the Parent process!
Parent PID: 484
```
Note: the "New Process" header appears to print twice. This isn't a bug — that `printf` runs once, before `fork()`, but its output is still sitting unflushed in stdout's buffer at the moment of the fork; both the parent and child inherit that buffered copy and flush it independently when they exit. The order of the parent/child blocks, and their PIDs, will vary between runs.