# Dual File Redirection Pipeline (grep < input.log > errors.txt)
A C program demonstrating simultaneous input and output redirection to discrete disk files before replacing the process image with `execlp("grep", ...)` to extract log lines.
## Description
This program models the standard shell redirection syntax `command < infile > outfile`:
1. The parent process writes sample application logs into `input.log`.
2. The parent spawns a worker child process via `fork()`.
3. In the child process:
   - Opens `input.log` in read-only mode and links it to `STDIN_FILENO` (fd 0) via `dup2()`.
   - Opens `errors.txt` in write-only mode (`O_CREAT | O_TRUNC`) and links it to `STDOUT_FILENO` (fd 1) via `dup2()`.
   - Closes the unneeded open file descriptors.
   - Executes `execlp("grep", "grep", "error", NULL)`.
4. `grep` reads from the redirected stdin stream and emits matching lines to the redirected stdout stream.
5. The parent synchronizes with `waitpid()` and displays the resulting `errors.txt` file.
6. Implements exhaustive error checking for all system calls (`open`, `write`, `close`, `fork`, `dup2`, `execlp`, `waitpid`).
## Features
- Full input/output redirection decoupling (`stdin < file1`, `stdout > file2`).
- Binary image replacement via `execlp()`.
- Error resilience with strict POSIX return value validation.
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
To clean up built binaries and created test files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./double_file_redirection_grep
```
## Usage Examples
**Dual File Redirection Output Example:**
```text


Dual File Redirection Pipeline (grep < input.log > errors.txt)

[PARENT] -> Prepared 'input.log' with sample log entries.
[PARENT] -> Spawning child process to execute: grep error < input.log > errors.txt...

[PARENT] -> Grep filtering finished. Filtered results in 'errors.txt':
============================================================
error: Database connection timeout occurred
error: Failed to write packet to socket
============================================================
```
