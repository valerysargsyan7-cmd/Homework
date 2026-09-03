# Failed Exec
A C program demonstrating error handling when replacing a child process image with a non-existent command using `execlp()`.
## Description
This program creates a child process via `fork()`. The child attempts to execute a non-existent command (`fake_command`) using the POSIX `execlp()` system call. Because the executable does not exist in `PATH`, `execlp()` returns `-1`, allowing the subsequent error handling code and `perror()` in the child to execute and report the failure before exiting. The parent waits for the child to finish.
## Features
- Child process creation using `fork()`.
- Process image replacement attempt using `execlp()`.
- Error reporting via `perror()` when `execlp()` fails.
- Process synchronization with `wait()`.
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
./failed_exec
```
## Usage Examples
**Failed Exec Output Example:**
```text


Failed Exec


Error: command doesn't exist!: No such file or directory
```
