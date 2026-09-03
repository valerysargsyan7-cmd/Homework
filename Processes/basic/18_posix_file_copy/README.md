# POSIX File Copy
A C program demonstrating reliable file copying using low-level POSIX system calls (`open()`, `read()`, `write()`, `close()`).
## Description
This program demonstrates copying data between files without buffering layers:
1. Opens the source file in read-only mode (`O_RDONLY`).
2. Opens/creates the target destination file with `O_WRONLY | O_CREAT | O_TRUNC` and permissions `0664`.
3. Reads content sequentially into a buffer via `read()`.
4. Writes the buffer contents to the destination file using `write()`, repeating until EOF.
5. Closes both descriptors and verifies the copied content.
## Features
- Low-level binary and text file copying.
- Error handling on file descriptors and read/write operations.
- Clean resource deallocation and verification.
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
./posix_file_copy
```
## Usage Examples
**POSIX File Copy Output Example:**
```text


POSIX File Copy


Copy status: DONE
Copied Content: Hello my name is John Smith
```
