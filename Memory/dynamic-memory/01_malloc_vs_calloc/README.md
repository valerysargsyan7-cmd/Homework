# Malloc vs Calloc Memory Allocation
A C program demonstrating the differences in initialization, usage, and deallocation between `malloc()` and `calloc()`.
## Description
This program demonstrates dynamic memory allocation on the heap:
1. **`malloc()`**: Allocates an uninitialized contiguous memory block. Its initial contents are indeterminate.
2. **`calloc()`**: Allocates memory for an array of elements and automatically zero-initializes all bytes.
3. Both arrays are inspected immediately after allocation, populated with structured sequential data, displayed, and cleanly freed using `free()`.
## Features
- Interactive sizing of dynamic arrays with input validation.
- Demonstration of indeterminate `malloc` memory vs zero-initialized `calloc` memory.
- Safe pointer validation against `NULL` returns.
- Guaranteed cleanup with `free()`.
- Standard C17 compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
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
./malloc_vs_calloc
```
## Usage Examples
**Malloc vs Calloc Output Example:**
```text


Malloc vs Calloc Memory Allocation

Enter size for malloc array: 3
Enter size for calloc array: 3

--- Uninitialized malloc values (indeterminate) ---
Malloc[0]: 0
Malloc[1]: 0
Malloc[2]: 0

--- Zero-initialized calloc values (guaranteed 0) ---
Calloc[0]: 0
Calloc[1]: 0
Calloc[2]: 0

--- Populated malloc array ---
Malloc[0]: 1
Malloc[1]: 2
Malloc[2]: 3

--- Populated calloc array ---
Calloc[0]: 10
Calloc[1]: 20
Calloc[2]: 30

Memory deallocated successfully.
```
