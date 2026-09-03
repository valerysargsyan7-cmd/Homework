# Concurrent File Append
A C program demonstrating concurrent, atomic file writing from multiple child processes sharing an open file descriptor in `O_APPEND` mode.
## Description
This program demonstrates file descriptor sharing across `fork()`. The parent opens `report.txt` with `O_APPEND | O_CREAT | O_WRONLY`. Two child processes are created:
- Child 7 writes `"AAAA\n"` 5 times.
- Child 8 writes `"BBBB\n"` 5 times.

Because the underlying open file description is opened in `O_APPEND` mode, all POSIX writes to the file are atomic at the file offset level without overwriting each other. The parent waits for both children, closes the descriptor, and reads back the combined output.
## Features
- Shared file descriptor inheritance across `fork()`.
- Guaranteed atomic writes via `O_APPEND`.
- Multi-process concurrent writing without data corruption.
- Parent cleanup and synchronized validation.
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
./concurrent_file_append
```
## Usage Examples
**Concurrent File Append Output Example:**
```text


Concurrent File Append


[PARENT] -> Both children finished writing to report.txt.

--- File Content (report.txt) ---
AAAA
AAAA
AAAA
AAAA
AAAA
BBBB
BBBB
BBBB
BBBB
BBBB
```
