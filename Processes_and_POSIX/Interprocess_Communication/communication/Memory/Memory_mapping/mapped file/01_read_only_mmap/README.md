# Read-Only File Memory Mapping (mmap)
A C program demonstrating zero-copy file inspection by mapping a disk file directly into the process's virtual address space using `mmap()` with `PROT_READ` and `MAP_PRIVATE`.
## Description
This program demonstrates file memory mapping using the POSIX `mmap()` system call:
1. Opens a file in read-only mode (`O_RDONLY`).
2. Calculates exact file size using `lseek(fd, 0, SEEK_END)`.
3. Maps the file pages into virtual memory using `mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0)`.
4. Outputs the file content directly from the mapped memory address using `write()`.
5. Unmaps memory via `munmap()` and closes the file descriptor.
## Features
- Zero-copy file reading via OS virtual memory page cache.
- `MAP_PRIVATE` copy-on-write mapping protection.
- Direct pointer-based memory access to file contents.
- Clean resource deallocation (`munmap` / `close`).
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
./read_only_mmap
```
## Usage Examples
**Read-Only Mmap Output Example:**
```text


Read-Only File Memory Mapping (mmap)

Reading file 'sample_mmap.txt' via mmap():

Hello from Memory-Mapped file!
This content is mapped directly into process virtual memory with PROT_READ.
```
