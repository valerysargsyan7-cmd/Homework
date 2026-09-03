# Dual Binary Files Concatenator
A C program demonstrating multi-file binary inspection, runtime dynamic memory sizing via `ftell()`, and sequential data concatenation across process boundaries.
## Description
This program demonstrates coordinating multi-file inputs across parent and child processes:
1. The parent dynamically generates two character buffers populated with `'A'` and `'B'` characters, writing them to `arr1.bin` and `arr2.bin`.
2. The child process opens both binary files, measures their exact lengths with `fseek(SEEK_END)` and `ftell()`, and allocates a single heap buffer sized to `size1 + size2 + 1`.
3. Reads the binary data from `arr1.bin` followed immediately by `arr2.bin` into contiguous memory using `fread()`.
4. Null-terminates the combined string and outputs the result.
5. The parent waits for child termination and cleans up.
## Features
- Dynamic memory sizing based on file system metadata (`ftell()`).
- Contiguous multi-file stream reading via `fread()`.
- Clean memory deallocation in both parent and child.
- Parent-child synchronization with `waitpid()`.
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
To clean up built binaries and created binary test files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./binary_files_concatenator
```
## Usage Examples
**Binary Files Concatenator Output Example:**
```text


Dual Binary Files Concatenator

[PARENT] -> Created 'arr1.bin' and 'arr2.bin' (25 bytes each).

[CHILD] -> Concatenated Data (25 + 25 = 50 bytes):
AAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBB

[CHILD] -> Work Status: DONE
[PARENT] -> Child completed concatenation. Finishing.
```
