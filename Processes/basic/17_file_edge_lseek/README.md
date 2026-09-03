# File Head & Tail Edge Reading with Lseek
A C program demonstrating positional seeking to the beginning (`SEEK_SET`) and relative from the end (`SEEK_END`) of a file using `lseek()`.
## Description
This program demonstrates non-linear file inspection:
1. Opens a text file in read-only mode (`O_RDONLY`).
2. Reads the initial 5 bytes from the start of the file (`START_TEXT`).
3. Repositions the file offset using `lseek(fd, -6, SEEK_END)` to locate the final 5 characters before the end of file.
4. Reads the trailing 5 bytes (`END_TEXT`) and displays both slices.
## Features
- Direct file offset navigation with `lseek()`.
- Reading head and tail boundary data from disk without reading intermediate content.
- Low-memory consumption file edge extraction.
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
To clean up built binaries and sample test files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./file_edge_lseek
```
## Usage Examples
**File Edge Reading Output Example:**
```text


File Head & Tail Edge Reading with Lseek

START_TEXT (first 5 bytes): Hello
END_TEXT (last 5 bytes): words
```
