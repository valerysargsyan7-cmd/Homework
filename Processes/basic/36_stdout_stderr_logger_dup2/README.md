# Dual Stream Redirection Logger via dup2()
A C program demonstrating simultaneous redirection of both standard output (`stdout`, descriptor `1`) and standard error (`stderr`, descriptor `2`) into a unified disk log file using `dup2()`.
## Description
This program demonstrates how Unix daemons and logging systems merge stdout and stderr:
1. Opens or creates a log file (`app.log`) in write-only mode (`O_WRONLY | O_CREAT | O_TRUNC`).
2. Duplicates the log file descriptor onto descriptor `1` (`STDOUT_FILENO`) via `dup2(fd, 1)`.
3. Duplicates the log file descriptor onto descriptor `2` (`STDERR_FILENO`) via `dup2(fd, 2)`.
4. Closes the original file descriptor to ensure single-reference lifecycle control.
5. Emits informational text to `stdout` via `printf()` and error diagnostics to `stderr` via `fprintf(stderr, ...)`.
6. Both streams are transparently multiplexed into `app.log`.
7. Includes strict error checking on all system call operations (`open`, `dup2`, `close`, `fflush`).
## Features
- Unified stream logging (`stdout` + `stderr` $\to$ logfile).
- Standard file descriptor table reconfiguration via `dup2()`.
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
To clean up built binaries and created log files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./stdout_stderr_logger_dup2
```
Verify the generated log:
```bash
cat app.log
```
## Usage Examples
**Execution & Log Output Example:**
```text
$ ./stdout_stderr_logger_dup2
$ cat app.log
[INFO] This text is normal standard output (stdout).
[ERROR] This text is an error log entry (stderr).
```
