# POSIX File Create, Write, and Read
A C program demonstrating low-level POSIX file creation, writing, and reading using system calls (`open()`, `write()`, `read()`, `close()`).
## Description
This program demonstrates foundational POSIX file descriptor management:
1. **Creation and Writing**: `create_and_write()` opens or creates a file with `open()` specifying flags `O_CREAT | O_RDWR | O_TRUNC` and file permissions `0664`. It writes a given string to disk using `write()`, closes the descriptor, and returns the byte count.
2. **Reading and Printing**: `read_and_print()` opens the file in read-only mode (`O_RDONLY`), reads the content into a buffer using `read()`, null-terminates the string safely, and prints the output to stdout.
## Features
- Low-level POSIX file creation and permission specification (`0664`).
- Direct buffer writing with `write()`.
- Unbuffered byte reading and null-terminated string printing with `read()`.
- Error reporting via `perror()` upon system call failure.
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
./file_create_read_write
```
## Usage Examples
**File Create, Write, and Read Output Example:**
```text


POSIX File Create, Write, and Read


Bytes written: 69
TEXT: Hello this is my first file that i create by C code and system calls

Bytes read: 69
```
