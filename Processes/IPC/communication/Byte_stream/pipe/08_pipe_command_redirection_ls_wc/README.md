# Unnamed Pipe Command Redirection Pipeline: ls | wc -l
A C program demonstrating inter-process command chaining using POSIX pipes (`pipe()`) and file descriptor duplication (`dup2()`) to execute the Unix shell pipeline `ls | wc -l`.
## Description
This program replicates the core mechanics of a Unix shell pipeline:
1. `pipe()` creates a unidirectional byte stream with read descriptor `fds[0]` and write descriptor `fds[1]`.
2. Spawns Child 1 (`Producer`):
   - Closes `fds[0]`.
   - Duplicates `fds[1]` onto descriptor `1` (`STDOUT_FILENO`) via `dup2()`.
   - Closes `fds[1]`.
   - Replaces its process image with `execlp("ls", "ls", NULL)`.
3. Spawns Child 2 (`Consumer`):
   - Closes `fds[1]`.
   - Duplicates `fds[0]` onto descriptor `0` (`STDIN_FILENO`) via `dup2()`.
   - Closes `fds[0]`.
   - Replaces its process image with `execlp("wc", "wc", "-l", NULL)`.
4. Parent coordinator closes all local pipe descriptors so that closing the producer's write-end causes `EOF` to be detected on the consumer's read-end.
5. Reaps both child processes with `waitpid()`.
6. Enforces robust error handling on every system call (`pipe`, `fork`, `dup2`, `close`, `execlp`, `waitpid`).
## Features
- Standard Unix shell pipeline implementation (`cmd1 | cmd2`).
- Strict file descriptor closure preventing hanging read blockers.
- Dual-child concurrent process coordination.
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
./pipe_command_redirection_ls_wc
```
## Usage Examples
**Pipe Command Redirection Output Example:**
```text
3
```
*(Outputs the exact line count of files in the current directory matching `ls | wc -l`)*
