# Reversing Array
A C program demonstrating pointer arithmetic and a two-pointer in-place swap technique to reverse the elements of an array.
## Description
This program reverses a fixed integer array (`rev_array[] = {1, 2, 3, 4, 5}`) in place. The `reverse` function uses two pointers — one starting at the beginning and one at the end of the array — swapping the values they point to and moving them toward each other until they meet. The reversed array is then printed.
## Features
- Pointer-based array traversal (no index variables used inside `reverse`).
- Two-pointer, in-place swap technique for reversal.
- Guard against a `NULL` pointer or non-positive size.
- Array size computed via `sizeof(rev_array) / sizeof(rev_array[0])`.
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
./reversing_array
```
## Usage Examples
**Reversing Array Example:**
```text


Reversing Array

Reversed array: 5 4 3 2 1 
```