# Byte-by-Byte File Equality Comparator
A C program demonstrating reliable, byte-by-byte file content equality verification using `fgetc()` and EOF synchronization checks.
## Description
This program demonstrates how to compare two arbitrary files for exact binary and text equality:
1. `are_files_equal()` opens both file paths using `fopen("r")`.
2. Concurrently reads characters from both streams using `fgetc()`.
3. Returns false (`0`) immediately upon detecting the first mismatched character.
4. Confirms that both streams reached `EOF` simultaneously, guaranteeing identical lengths and content.
5. Closes both streams cleanly.
## Features
- Low-memory character-by-character comparison via `fgetc()`.
- Early exit on mismatch detection.
- Handling of length mismatches when one file ends before the other.
- Robust stream error checking.
- Standard C17 compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
## Building
To compile the project, run:
```bash
make
```
To clean up built binaries and sample test files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./file_equality_comparator
```
## Usage Examples
**File Equality Comparator Output Example:**
```text


Byte-by-Byte File Equality Comparator

Comparing 'test1.txt' and 'test2.txt':
Result: Files are IDENTICAL (Equal)

Comparing 'test1.txt' and 'test3.txt':
Result: Files are DIFFERENT
```
