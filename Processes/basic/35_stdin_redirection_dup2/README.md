# Standard Input Redirection via dup2()
A C program demonstrating file descriptor replacement using `dup2()` to redirect standard input (`stdin`, descriptor `0`) to read from a disk file.
## Description
This program demonstrates Unix I/O redirection at the file descriptor table level:
1. Prepares a disk file (`data.txt`) with sample data.
2. Opens the file in read-only mode (`O_RDONLY`).
3. Uses `dup2(fd, STDIN_FILENO)` to duplicate the file descriptor onto descriptor `0` (`stdin`).
4. Closes the original file descriptor to prevent descriptor leaks.
5. Invokes standard library input function `fgets(..., stdin)`, which transparently reads from the disk file rather than the keyboard.
6. Prints the retrieved content to stdout.
7. Features comprehensive error checking on all system calls (`open`, `dup2`, `close`, `write`, `fgets`).
## Features
- Low-level standard input descriptor replacement via `dup2()`.
- Error resilience with strict POSIX return value validation.
- Clean descriptor lifecycle management.
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
./stdin_redirection_dup2
```
## Usage Examples
**Stdin Redirection Output Example:**
```text


Standard Input Redirection via dup2()

Output read from redirected stdin:
Line read directly from redirected stdin via dup2!
```
