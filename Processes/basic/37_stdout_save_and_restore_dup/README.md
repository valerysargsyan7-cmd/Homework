# Stdout Redirection & Restoration via dup() and dup2()
A C program demonstrating temporary output redirection and subsequent restoration of standard output (`stdout`) to the terminal screen using `dup()` and `dup2()`.
## Description
This program demonstrates how shell environments and debugging libraries capture output temporarily and safely restore it:
1. Duplicates the original terminal `stdout` descriptor (fd 1) into an available backup slot using `dup(STDOUT_FILENO)`.
2. Opens a target disk file (`temp.txt`) and redirects descriptor 1 to it via `dup2(fd, STDOUT_FILENO)`.
3. Emits output via standard `printf()` and flushes standard I/O buffers with `fflush(stdout)`.
4. Restores the terminal output stream by duplicating the backup descriptor back onto fd 1 via `dup2(saved_stdout, STDOUT_FILENO)`.
5. Closes the backup descriptor to prevent resource leaks.
6. Prints a confirmation message directly to the restored terminal screen and verifies file contents.
7. Features comprehensive error validation across every system call.
## Features
- Safe saving and restoration of POSIX standard streams.
- Atomic stream redirection with `dup2()`.
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
To clean up built binaries and created temp files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./stdout_save_and_restore_dup
```
## Usage Examples
**Stdout Save and Restore Output Example:**
```text


Stdout Redirection & Restoration via dup() and dup2()

[SUCCESS] Output stream successfully restored back to terminal screen!

Contents verified inside temp.txt:
  "This text was written while stdout was redirected to temp.txt!"
```
