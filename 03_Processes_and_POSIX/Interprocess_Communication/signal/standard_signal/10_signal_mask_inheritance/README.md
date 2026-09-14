# Signal Mask Inheritance
A C program demonstrating POSIX signal mask inheritance across `fork()` and subsequent runtime mask modification via `sigprocmask()`.
## Description
This program demonstrates that child processes created via `fork()` inherit their parent process's signal mask. The parent configures a signal set containing `SIGINT` (Ctrl+C) and applies it with `sigprocmask(SIG_BLOCK, ...)`. Upon forking, the child inherits the blocked status of `SIGINT`. Inside the child process, `sigprocmask(SIG_UNBLOCK, ...)` is called to restore normal responsiveness to `SIGINT`. The child sleeps for 5 seconds and exits, while the parent waits with `wait()`.
## Features
- Signal mask initialization using `sigemptyset()` and `sigaddset()`.
- Blocking signal delivery at parent level using `sigprocmask(SIG_BLOCK)`.
- Demonstration of child signal mask inheritance across `fork()`.
- Dynamic unmasking of signals within child using `sigprocmask(SIG_UNBLOCK)`.
- Parent synchronization using `wait()`.
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
./signal_mask_inheritance
```
## Usage Examples
**Signal Mask Inheritance Output Example:**
```text


Signal Mask Inheritance

[PARENT] -> SIGINT (Ctrl+C) is now blocked.

[CHILD] -> I inherited the signal mask!
[CHILD] -> Unblocking SIGINT...
[CHILD] -> SIGINT is unblocked. Sleeping 5 seconds...

[CHILD] -> Exiting by myself

[PARENT] -> Child is done
```
