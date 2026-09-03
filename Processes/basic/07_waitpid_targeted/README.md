# Waitpid Targeted
A C program demonstrating non-FIFO process synchronization and targeted process waiting using POSIX `waitpid()`.
## Description
This program demonstrates how a parent process can wait specifically for a particular child process rather than any arbitrary child. The parent spawns two children:
- Child 1 sleeps for 1 second.
- Child 2 sleeps for 4 seconds.

The parent uses `waitpid(child_proc_2, NULL, 0)` to explicitly block until Child 2 has terminated, irrespective of whether Child 1 finishes first. After Child 2 completes, the parent reaps Child 1 and exits cleanly.
## Features
- Forking multiple concurrent child processes.
- Targeted child synchronization using `waitpid()` with an explicit PID.
- Demonstration of out-of-order process waiting.
- Prevention of zombie processes through complete cleanup.
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
./waitpid_targeted
```
## Usage Examples
**Waitpid Targeted Output Example:**
```text


Waitpid Targeted

[CHILD 1] -> Sleeping for 1 second...

[PARENT] -> Waiting specifically for Child 2 (PID: 14205)...
[CHILD 2] -> Sleeping for 4 seconds...
[CHILD 1] -> Done.
[CHILD 2] -> Done.
[PARENT] -> Child 2 finished, now parent can exit
```
