# Matrix
A C program demonstrating 2D array storage, nested `for` loop input and output, and interactive per-cell input with validation.
## Description
This program prompts the user to enter 9 integers via standard input (`stdin`), filling a 3×3 two-dimensional array (`matrix[3][3]`) row by row while validating each input. It then prints the matrix in its row-by-row grid form.
## Features
- 2D array storage (`matrix[3][3]`).
- Nested `for` loop input, addressing each cell by row and column.
- Nested `for` loop output, printing the matrix in grid form.
- Error handling for invalid numeric inputs.
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
./matrix
```
## Usage Examples
**Matrix Example:**
```text


Matrix

Enter matrix[0][0]: 1
Enter matrix[0][1]: 2
Enter matrix[0][2]: 3
Enter matrix[1][0]: 4
Enter matrix[1][1]: 5
Enter matrix[1][2]: 6
Enter matrix[2][0]: 7
Enter matrix[2][1]: 8
Enter matrix[2][2]: 9

Matrix:

1 2 3 
4 5 6 
7 8 9 
```
**Invalid Input Error Example:**
```text


Matrix

Enter matrix[0][0]: 1
Enter matrix[0][1]: 2
Enter matrix[0][2]: x

[ERROR] Invalid input!
```