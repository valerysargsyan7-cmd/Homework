# Dynamic 2D Lower-Triangular Matrix
A C program demonstrating pointer-to-pointer (`int **`) dynamic two-dimensional array allocation, lower-triangular populating, and structured memory deallocation.
## Description
This program demonstrates allocating multi-dimensional arrays dynamically on the heap:
1. Prompts the user to enter matrix dimension \(N\).
2. Allocates an array of row pointers on the heap: `int **matrix = malloc(N * sizeof(int *))`.
3. Allocates each individual row array dynamically with `malloc()`.
4. Populates elements in lower-triangular format (\(j \le i\)) with values \(matrix[i][j] = i + j\).
5. Displays the formatted triangular matrix to the console.
6. Cleanly deallocates memory in the correct inverse order: freeing each row first, then freeing the master row-pointer array.
## Features
- Pointer-to-pointer (`int **`) dynamic 2D array representation.
- Safe dynamic memory error handling preventing partial leaks on allocation failure.
- Formatted lower-triangular output.
- Complete multi-stage deallocation via `free()`.
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
./dynamic_triangular_matrix
```
## Usage Examples
**Dynamic Triangular Matrix Output Example:**
```text


Dynamic 2D Lower-Triangular Matrix

Enter matrix row count (dimension N): 5

---- LOWER TRIANGULAR MATRIX ----

  0 
  1   2 
  2   3   4 
  3   4   5   6 
  4   5   6   7   8 

Matrix memory deallocated cleanly.
```
