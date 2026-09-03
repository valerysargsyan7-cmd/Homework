# Mmap Shared Memory vs Malloc Heap (Process Isolation)
A C program proving process memory isolation vs shared memory IPC by comparing `malloc()` heap memory behavior against `mmap(MAP_SHARED | MAP_ANONYMOUS)` across `fork()`.
## Description
This program demonstrates how modern operating systems isolate process memory:
1. Allocates two 5-element buffers in the parent:
   - `shared_mmap_arr`: Allocated using `mmap(MAP_SHARED | MAP_ANONYMOUS)`.
   - `private_heap_arr`: Allocated using standard heap `malloc()`.
2. The parent calls `fork()`.
3. The child modifies elements in both buffers.
4. The parent waits for the child to exit and checks both buffers:
   - `shared_mmap_arr`: Reflects the child's modifications, proving zero-copy shared memory.
   - `private_heap_arr`: Remains unchanged at 0 in the parent, proving Copy-On-Write virtual memory isolation.
5. Deallocates both regions using `munmap()` and `free()`.
## Features
- Architectural proof of process isolation vs shared memory.
- Multi-region heap and virtual page allocation.
- Parent-child synchronization with `wait()`.
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
./mmap_vs_malloc_ipc
```
## Usage Examples
**Mmap vs Malloc IPC Output Example:**
```text


Mmap Shared Memory vs Malloc Heap (Process Isolation)

Initial states in parent: all elements = 0
[CHILD] -> Writing 10, 20, 30, 40, 50 to both buffers in child...

[PARENT] -> Inspecting values in parent process after child exited:

--- MAP_SHARED Array (Visible across processes) ---
  mmap[0] = 10
  mmap[1] = 20
  mmap[2] = 30
  mmap[3] = 40
  mmap[4] = 50

--- Malloc Heap Array (Isolated in parent address space) ---
  malloc[0] = 0
  malloc[1] = 0
  malloc[2] = 0
  malloc[3] = 0
  malloc[4] = 0

Conclusion: 'malloc' heap memory is isolated per process.
            'mmap(MAP_SHARED)' shares physical memory across processes.
```
