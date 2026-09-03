# Child Exit Status
A C program demonstrating child process termination status handling and exit code extraction using `wait()`, `WIFEXITED`, and `WEXITSTATUS`.
## Description
This program creates a child process using `fork()`. The child prompts the user for an exit code integer, and terminates with `exit(exit_num)`. The parent waits for the child using `wait(&status)` and inspects the status word using standard POSIX macros:
- `WIFEXITED(status)`: Evaluates to true if the child terminated normally.
- `WEXITSTATUS(status)`: Extracts the 8-bit exit status code returned by the child.
- `WIFSIGNALED(status)`: Evaluates to true if the child was terminated by an unhandled signal.
- `WTERMSIG(status)`: Extracts the terminating signal number if signaled.
## Features
- Child process creation via `fork()`.
- Dynamic exit code propagation via `exit()`.
- Parent status word inspection with `WIFEXITED` and `WEXITSTATUS`.
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
./exit_status
```
## Usage Examples
**Normal Exit Example:**
```text


Child Exit Status

[CHILD] -> Enter number for exiting: 42

[PARENT] -> Child exited normally with status: 42
```
