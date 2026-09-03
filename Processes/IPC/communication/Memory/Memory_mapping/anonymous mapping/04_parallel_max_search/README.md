# Parallel Dataset Max Search via Mmap & Shared Memory
A C program demonstrating parallel binary dataset scanning across multiple child processes where the dataset is mapped via file-backed `mmap()` and partial maximum results are returned through anonymous shared memory (`MAP_ANONYMOUS`).
## Description
This program combines file-backed and anonymous memory mappings for distributed search:
1. **File-Backed Mapping (`par_file`)**: The parent maps a large binary dataset (10,000 integers) into virtual memory with `MAP_SHARED` so all child processes can read without copying.
2. **Anonymous Shared Return Buffer (`child_max`)**: An anonymous shared array of size 2 is created using `MAP_SHARED | MAP_ANONYMOUS`.
3. **Child 1**: Scans partition 1 (indices 0..4999), finds local max, and writes it directly to `child_max[0]`.
4. **Child 2**: Scans partition 2 (indices 5000..9999), finds local max, and writes it directly to `child_max[1]`.
5. **Parent**: Synchronizes both children via `wait()`, compares the two partition maximums to determine the global maximum, and unmaps all shared pages.
## Features
- Hybrid memory mapping architecture (file-backed dataset + anonymous shared return channel).
- Zero memory copying during parallel dataset scanning.
- Multi-child parallel divide-and-conquer search.
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
To clean up built binaries and dataset files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./parallel_max_search
```
## Usage Examples
**Parallel Max Search Output Example:**
```text


Parallel Dataset Max Search via Mmap & Shared Memory

[CHILD 1] -> Max in partition 1 (0..4999): 99982
[CHILD 2] -> Max in partition 2 (5000..9999): 99995

[PARENT] -> Both children finished searching.
[PARENT] -> Partition 1 Max: 99982
[PARENT] -> Partition 2 Max: 99995

[PARENT] -> Overall Global Maximum: 99995 (Found by Child 2)
```
