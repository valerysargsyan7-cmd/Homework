# Dynamic Array Factory Module
A modular C library project implementing dynamic heap allocation and array initialization helper functions.
## Description
This project demonstrates creating a reusable factory routine for dynamic arrays:
1. **Helper Library (`mem_helper.h` / `mem_helper.c`)**: Exposes `int *creat_and_fill(int size, int default_val)` to dynamically allocate an integer array on the heap via `malloc()` and populate every element with a requested default value.
2. **Driver (`main.c`)**: Interactively queries the user for array dimension and initialization value, calls the factory, prints the resulting initialized array, and ensures `free()` deallocation.
## Project Structure
```text
06_dynamic_array_factory/
├── main.c
├── Makefile
├── mem_helper.c
├── mem_helper.h
└── README.md
```
## Features
- Modular multi-file architecture with separate headers.
- Input validation on dynamic sizing parameters.
- Robust heap error checking.
- Clean resource management.
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
./dynamic_array_factory
```
## Usage Examples
**Dynamic Array Factory Output Example:**
```text


Dynamic Array Factory Module

Enter size of array: 5
Enter default value to fill array: 42

--- Array Elements (5 elements initialized with 42) ---
42 42 42 42 42 
Memory deallocated successfully.
```
