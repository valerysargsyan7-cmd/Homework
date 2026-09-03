# Killing Process
A C program demonstrating asynchronous process termination using the POSIX `kill()` function with `SIGKILL`.
## Description
This program creates a child process with `fork()` that enters an infinite loop, periodically printing a status message. The parent process sleeps for 3 seconds, then explicitly sends `SIGKILL` to the child process using `kill()`, ensuring immediate termination. The parent waits for the child and inspects its termination status via `WIFSIGNALED` and `WTERMSIG`.
## Features
- Child process creation using `fork()`.
- Unconditional child process termination via `kill()` with `SIGKILL`.
- Signal-based exit inspection using `waitpid()`, `WIFSIGNALED()`, and `WTERMSIG()`.
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
./killing_process
```
## Usage Examples
**Killing Process Output Example:**
```text


Killing Process


Child is running...

Child is running...

Child is running...

Sending SIGKILL to child...
Child terminated by signal: 9
Program finished.
```
