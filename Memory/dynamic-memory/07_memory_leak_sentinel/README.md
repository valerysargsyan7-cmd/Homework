# Memory Leak Sentinel Module
A modular C memory management sentinel library implementing internal allocation bookkeeping, tracked deallocation (`safe_free`), and emergency sweep deallocation (`force_cleanup`).
## Description
This project demonstrates creating a memory tracking layer on top of standard dynamic allocation:
1. **`safe_malloc(size_t size)`**: Allocates heap memory with `malloc()` and records the returned pointer in an internal static registry.
2. **`safe_free(void *ptr)`**: Locates the pointer in the internal registry, calls standard `free()`, and clears the tracking slot.
3. **`force_cleanup()`**: Iterates through all tracked pointers that were not freed by the caller, sweeps through the list to free active leaks, and reports the exact count of reclaimed blocks.
## Project Structure
```text
07_memory_leak_sentinel/
├── main.c
├── Makefile
├── README.md
├── sentinel.c
└── sentinel.h
```
## Features
- Tracked heap allocation registry.
- Leak detection and batch cleanup mechanism.
- Async signal handling support for emergency deallocation on exit.
- Modular library architecture.
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
./memory_leak_sentinel
```
## Usage Examples
**Memory Leak Sentinel Output Example:**
```text


Memory Leak Sentinel Module

Allocating sample heap buffers via safe_malloc()...
Explicitly freeing 2 pointers with safe_free()...
3 allocated buffers remain untracked by caller (simulated leaks).
Press Ctrl+C (or wait 2s) to trigger force_cleanup()...

Triggering sentinel sweep...

Force cleanup status: DONE
Leaks intercepted and cleaned: 3
Program exiting cleanly.
```
