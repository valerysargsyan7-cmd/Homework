# In-Place Whole-File Reversal via Mmap
A C program demonstrating two-pointer in-place byte reversal of an entire file on disk using memory mapping (`mmap()`) with `MAP_SHARED`.
## Description
This program demonstrates in-place data transformations on disk files:
1. Opens a file in read-write mode (`O_RDWR`).
2. Calculates exact file size via `lseek()`.
3. Maps the file pages into process virtual memory with `PROT_READ | PROT_WRITE` and `MAP_SHARED`.
4. Uses a two-pointer algorithm (`start` and `end`) to swap characters from the outer boundaries toward the center directly in the mapped page buffer.
5. Flushes and cleans up the mapping with `munmap()` and `close()`.
6. Validates the resulting reversed file on disk.
## Features
- In-place file reversal without loading into separate heap allocations.
- Direct memory-mapped two-pointer byte swapping.
- `MAP_SHARED` kernel page sync.
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
To clean up built binaries and sample files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./reverse_file_mmap
```
## Usage Examples
**Reverse File Mmap Output Example:**
```text


In-Place Whole-File Reversal via Mmap

Original file 'reverse_sample.txt' content:
"ABCDEFGHIJKLM"

Reversing file in-place via mmap()...

Reversed file content on disk:
"MLKJIHGFEDCBA"
```
