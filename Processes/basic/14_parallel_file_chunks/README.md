# Parallel File Chunks Extraction
A C program demonstrating multi-process parallel reading of non-overlapping file segments into separate destination files.
## Description
This program demonstrates concurrent file extraction. The parent initializes `source.txt` with sample data (`"0123456789ABCDEFGHIJ"`). Two child processes are forked to extract specific segments in parallel:
- **Child 10**: Reads the first 10 bytes (offset 0 to 9) and writes them to `part1.txt`.
- **Child 11**: Reads the second 10 bytes (offset 10 to 19) and writes them to `part2.txt`.

The parent synchronizes with both children using `wait()`, closes descriptors, and validates the contents of both generated partition files.
## Features
- Shared source file access among concurrent child processes.
- Non-overlapping positional file reads via `pread()`.
- Independent output file generation (`part1.txt` and `part2.txt`).
- Parent validation and verification of extracted partitions.
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
To clean up built binaries and generated partition files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./parallel_file_chunks
```
## Usage Examples
**Parallel File Chunks Output Example:**
```text


Parallel File Chunks Extraction

[PARENT] -> Child 10 done (part1.txt written)
[PARENT] -> Child 11 done (part2.txt written)

Verification:
Part 1: 0123456789
Part 2: ABCDEFGHIJ
```
