# In-Place Character Replacement via Mmap
A C program demonstrating direct in-place disk file mutation using memory mapping (`mmap()`) with `PROT_READ | PROT_WRITE` and `MAP_SHARED`.
## Description
This program demonstrates in-place file editing without standard stream write loops:
1. Opens a file in read-write mode (`O_RDWR`).
2. Maps the file pages with `MAP_SHARED` flags so that writes to the memory buffer directly update the underlying file on disk.
3. Iterates over the memory pointer buffer, replacing every occurrence of a target character `old_c` with `new_c`.
4. Flushes and cleans up the mapping using `munmap()` and `close()`.
5. Reads back the file from disk to verify persistent in-place modification.
## Features
- In-place binary and text modification without intermediate temp files.
- `MAP_SHARED` disk synchronization.
- Pointer-based linear scanning.
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
To clean up built binaries and test files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./replace_char_mmap
```
## Usage Examples
**Replace Char Mmap Output Example:**
```text


In-Place Character Replacement via Mmap

Original file 'replace_sample.txt' content:
banana and apple and avocado

Replacing all occurrences of 'a' with 'X' in-place via mmap()...
Modified file content after unmapping:
bXnXnX Xnd Xpple Xnd XvocXdo
```
