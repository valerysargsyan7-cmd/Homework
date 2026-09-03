# Private vs Shared Mmap (Copy-On-Write Demonstration)
A C program demonstrating the architectural difference between `MAP_SHARED` (direct disk page updates) and `MAP_PRIVATE` (process-isolated Copy-On-Write pages).
## Description
This program demonstrates memory mapping isolation:
1. Maps the same file twice simultaneously:
   - `shared_ptr`: mapped with `MAP_SHARED`.
   - `private_ptr`: mapped with `MAP_PRIVATE`.
2. Writes character `'#'` to `private_ptr[0]`. The OS allocates a private Copy-On-Write (COW) page for the process without affecting the disk file or other mappings.
3. Writes character `'*'` to `shared_ptr[1]`. The OS updates the shared file cache, which is immediately propagated to the disk file.
4. Unmaps both pointers and reads the disk file to confirm that only the `MAP_SHARED` mutation is persistent.
## Features
- Direct side-by-side comparison of `MAP_SHARED` vs `MAP_PRIVATE`.
- Copy-On-Write (COW) virtual memory demonstration.
- Clean memory deallocation with `munmap()`.
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
./private_vs_shared_mmap
```
## Usage Examples
**Private vs Shared Mmap Output Example:**
```text


Private vs Shared Mmap (Copy-On-Write Demonstration)

Initial file content: "0123456789"

Writing '#' to index 0 of MAP_PRIVATE pointer...
Writing '*' to index 1 of MAP_SHARED pointer...

Contents from MAP_PRIVATE pointer: "#123456789"
Contents from MAP_SHARED pointer:  "0*23456789"

Final content on DISK: "0*23456789"
Explanation: MAP_SHARED change ('*') was written to disk.
             MAP_PRIVATE change ('#') remained in private process page (COW).
```
