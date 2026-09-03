# File Reader Module
A modular C library project providing whole-file reading into heap-allocated dynamic buffers with automated byte sizing via `fseek()` and `ftell()`.
## Description
This project demonstrates creating a reusable file-reading utility:
1. **Module Interface (`file_reader.h` / `file_reader.c`)**: Exposes `char *read_entire_file(const char *path)`, which queries the file stream size, allocates an exact `file_len + 1` heap block, loads all bytes with `fread()`, null-terminates the string, and returns the pointer.
2. **Driver (`main.c`)**: Demonstrates calling the module on a sample file, displaying the loaded text, and managing heap deallocation.
## Project Structure
```text
31_file_reader_module/
├── file_reader.c
├── file_reader.h
├── main.c
├── Makefile
└── README.md
```
## Features
- Dynamic memory allocation based on exact file length (`ftell()`).
- Error-resilient stream opening and seeking.
- Reusable modular library architecture.
- Caller-side resource cleanup.
- Standard C17 and POSIX compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
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
./file_reader_module
```
## Usage Examples
**File Reader Module Output Example:**
```text


File Reader Module

Reading file 'sample_data.txt'...

====[ TEXT CONTENT ]====

This is sample content read dynamically by the File Reader Module.
It calculates exact file length and allocates a properly sized buffer.

========================
```
