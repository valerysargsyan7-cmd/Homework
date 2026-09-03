# Shared File Lseek Modification
A C program demonstrating in-place file content modification at specific byte offsets using `lseek()` across parent and child processes.
## Description
This program demonstrates file offset positioning with `lseek()`. The sequence is:
1. The parent creates and initializes `data.txt` with a 10-byte string `"0000000000"`.
2. The child process inherits the open descriptor, uses `lseek(fd, 3, SEEK_SET)` to advance the offset to position 3, and overwrites 4 bytes with `"XXXX"`.
3. The parent waits for the child to finish, rewinds the file offset back to position 0 (`lseek(fd, 0, SEEK_SET)`), and reads back the modified content (`"000XXXX000"`).
## Features
- File descriptor inheritance across `fork()`.
- Explicit file offset manipulation via `lseek()`.
- In-place binary and text modification without file truncations.
- Parent-child read-after-write synchronization via `wait()`.
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
./shared_file_lseek
```
## Usage Examples
**Shared File Lseek Output Example:**
```text


Shared File Lseek Modification


[PARENT] -> File content after child lseek write: 000XXXX000
```
