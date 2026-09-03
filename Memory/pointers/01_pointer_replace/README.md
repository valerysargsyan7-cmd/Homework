# Pointer Replace
A C program demonstrating pointer dereferencing, a manual value swap via a temporary variable, and absolute-difference calculation.
## Description
This program prompts the user to enter two integers via standard input (`stdin`), stored in variables accessed through pointers (`ptr_x`, `ptr_y`). It prints the values before swapping, swaps them in place using a temporary variable and pointer dereferencing, prints the values after swapping, and prints the absolute difference between them using `abs`.
## Features
- Pointer-based variable access (`ptr_x`, `ptr_y`) instead of direct variable use.
- Manual value swap via a temporary variable and pointer dereferencing.
- Before/after output to show the effect of the swap.
- Absolute-difference calculation via `abs`.
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
./pointer_replace
```
## Usage Examples
**Pointer Replace Example:**
```text


Pointer Replace


Enter first number to replace: 5

Enter second number to replace: 9

Without replacing: 5, 9
With replace: 9, 5
Difference: 4
```
**Invalid Input Error Example:**
```text


Pointer Replace


Enter first number to replace: x
[ERROR] Invalid input for first number!
```