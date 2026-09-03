# Process Information
A C program demonstrating POSIX system calls to retrieve and print information about the running process.
## Description
This program calls three POSIX functions — `getpid()`, `getppid()`, and `getpgrp()` — to retrieve the current process's ID, its parent process's ID, and its process group ID, and prints all three.
## Features
- Retrieval of the current process ID via `getpid()`.
- Retrieval of the parent process ID via `getppid()`.
- Retrieval of the process group ID via `getpgrp()`.
- Standard C17 compliant code (requires POSIX; not portable to non-POSIX systems).
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS), since this program uses `<unistd.h>`
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
./process_info
```
## Usage Examples
**Process Information Example:**
```text


Process Information

Process ID: 473
Parent Process ID: 463
Process Group ID: 463
```