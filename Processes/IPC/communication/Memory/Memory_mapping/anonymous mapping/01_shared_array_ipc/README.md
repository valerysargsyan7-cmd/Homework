# Anonymous Shared Memory Array (IPC)
A C program demonstrating zero-copy inter-process communication between parent and child processes using `mmap()` with `MAP_SHARED | MAP_ANONYMOUS`.
## Description
This program demonstrates anonymous memory sharing without requiring backing disk files:
1. `create_shared_int_array()` requests a shared anonymous memory page using `mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0)`.
2. When the parent calls `fork()`, the anonymous shared memory mapping is preserved and shared across both processes.
3. The child populates values directly into the shared buffer.
4. The parent waits for child completion and reads back the populated array directly with zero IPC overhead.
5. Deallocates the shared page using `munmap()`.
## Features
- Zero-copy shared memory IPC without file descriptor dependencies.
- `MAP_ANONYMOUS` memory page allocation.
- Parent-child shared array mutation and inspection.
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
To clean up built binaries:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./shared_array_ipc
```
## Usage Examples
**Shared Array IPC Output Example:**
```text


Anonymous Shared Memory Array (IPC)

[CHILD] -> Populating shared array in child process...
[CHILD] -> Finished writing to shared memory. Exiting.

[PARENT] -> Reading shared array populated by child:
Element[0] = 5
Element[1] = 10
Element[2] = 15
Element[3] = 20
Element[4] = 25
Element[5] = 30
Element[6] = 35
Element[7] = 40
Element[8] = 45
Element[9] = 50

[PARENT] -> Memory unmapped cleanly.
```
