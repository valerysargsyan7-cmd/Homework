# Dynamic Even Number Filtering
A C program demonstrating two-phase dynamic memory allocation to generate an initial random array, compute exact filtered size, allocate a precisely-sized destination array, and filter elements.
## Description
This program demonstrates efficient dynamic memory sizing:
1. Prompts the user for array length and dynamically allocates an initial array with `malloc()`.
2. Populates the array with pseudo-random integers (\(1 \dots 100\)).
3. Computes the count of even integers in the array.
4. Dynamically allocates a second array sized to the exact count of even numbers (`sizeof(int) * even_count`), preventing wasted heap space.
5. Copies all even values, prints both arrays, and deallocates all heap blocks.
## Features
- Dynamic memory sizing based on runtime conditions.
- Zero heap waste via exact-sized secondary allocation.
- Input validation and `NULL` pointer checks.
- Clean deallocation with `free()`.
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
./dynamic_even_filter
```
## Usage Examples
**Dynamic Even Filter Output Example:**
```text


Dynamic Even Number Filtering

Enter size of random numbers array: 6

Generated Random Array:
23 48 12 77 90 31

Found 3 even numbers.
Filtered Even Array:
48 12 90

Memory cleaned up successfully.
```
