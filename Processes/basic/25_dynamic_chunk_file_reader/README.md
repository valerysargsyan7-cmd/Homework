# Dynamic Chunk File Reader with Realloc
A C program demonstrating fixed-size chunk file reading (`fread()`) combined with dynamic heap buffer reallocation (`realloc()`) in a child process.
## Description
This program demonstrates processing arbitrarily large input files without hardcoded buffer size limits:
1. The parent creates and writes sample text to `Parent_large_file.txt`.
2. The child process opens the stream and reads the file in fixed 64-byte chunks using `fread()`.
3. If accumulating bytes exceed the allocated capacity, the child dynamically expands the buffer using `realloc()` in 64-byte increments.
4. Once EOF is reached, the buffer is null-terminated, printed, and freed.
5. The parent waits for the child to finish and cleans up resources.
## Features
- Chunk-based incremental reading via `fread()`.
- Dynamic buffer scaling on demand with `realloc()`.
- Safe temporary pointer realloc checks to prevent memory leaks.
- Parent-child process synchronization with `wait()`.
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
./dynamic_chunk_file_reader
```
## Usage Examples
**Dynamic Chunk File Reader Output Example:**
```text


Dynamic Chunk File Reader with Realloc


[CHILD] -> Read 164 bytes dynamically:
"This is a large file text that I create as a parent process. It contains multiple sentences to demonstrate dynamic buffer growth using 64-byte chunk reads and reallocation."
[CHILD] -> Work Status: DONE

[PARENT] -> Child finished reading. File closed.
```
