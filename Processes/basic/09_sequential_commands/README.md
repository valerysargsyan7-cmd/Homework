# Sequential Commands Execution
A C program demonstrating the sequential creation, execution, and reaping of child processes running external system utilities (`ls -l` and `uname -a`).
## Description
This program demonstrates coordinating multi-stage system utility execution across multiple processes. It forks a first child process to run `ls -l` via `execlp()`, and the parent synchronizes until its completion using `waitpid()`. Once the first command has concluded, the parent forks a second child process to run `uname -a` via `execlp()`, and waits again with `waitpid()`.
## Features
- Ordered sequential execution of system binaries (`ls` and `uname`).
- Process image overlay via `execlp()`.
- Synchronous phase transitions managed via `waitpid()`.
- Error reporting via `perror()` upon failed child creation or overlay.
- Standard C17 and POSIX compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system with `ls` and `uname` available on `PATH`
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
./sequential_commands
```
## Usage Examples
**Sequential Commands Output Example:**
```text


Sequential Commands Execution

-rw-r--r-- 1 user group  350 Sep  1 20:00 Makefile
-rw-r--r-- 1 user group 1200 Sep  1 20:00 README.md
-rw-r--r-- 1 user group  850 Sep  1 20:00 main.c

[PARENT] -> First child done his work

--------------------------------

Linux workstation 6.6.0-generic #1 SMP PREEMPT_DYNAMIC x86_64 GNU/Linux

[PARENT] -> Second child done his work
```
