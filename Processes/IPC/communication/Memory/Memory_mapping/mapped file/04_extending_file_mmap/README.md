# Extending File Size via Ftruncate & Mmap
A C program demonstrating dynamic disk file growth using `ftruncate()` to allocate disk pages and `mmap()` with `MAP_SHARED` to populate the expanded region.
## Description
Memory-mapping an empty or smaller file beyond its current EOF causes a `SIGBUS` fault. This program demonstrates the correct POSIX pattern for growing a file before memory-mapping it:
1. Creates an empty disk file.
2. Extends the underlying file allocation to 1024 bytes using `ftruncate(fd, 1024)`.
3. Maps the full 1024-byte range with `mmap()` using `PROT_READ | PROT_WRITE` and `MAP_SHARED`.
4. Writes data directly into the newly extended virtual memory range.
5. Flushes and unmaps with `munmap()` and verifies persistence on disk.
## Features
- File expansion via `ftruncate()`.
- Safe memory mapping avoiding `SIGBUS` faults.
- Direct pointer writing to newly allocated disk pages.
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
./extending_file_mmap
```
## Usage Examples
**Extending File Mmap Output Example:**
```text


Extending File Size via Ftruncate & Mmap

Initial file created (0 bytes).
File capacity extended to 1024 bytes using ftruncate().
Written string to extended memory map: "This file was extended using ftruncate and populated via mmap!"

Read back from disk: "This file was extended using ftruncate and populated via mmap!"
```
