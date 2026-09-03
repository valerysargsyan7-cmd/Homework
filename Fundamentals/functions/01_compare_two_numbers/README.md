# Compareing Two Numbers
A C program demonstrating pointer parameters, an output parameter for status signaling, a separate comparison function, and conditional branching to determine the larger of two integers.
## Description
This program prompts the user to enter two integers via standard input (`stdin`). It passes pointers to both values, along with a pointer to an `are_equal` flag, into a `compareing` function, which compares the two values and returns the larger one, setting `are_equal` if they match. The result is then printed.
## Features
- Pointer-based function parameters (`int *`) for comparison.
- Output parameter (`are_equal_ptr`) to signal equality independently of the return value, so any integer (including negative values) can be a valid maximum.
- Separate `compareing` function for the comparison logic.
- Conditional branching to identify the maximum of two integers.
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
./compareing_two_numbers
```
## Usage Examples
**Maximum Found Example:**
```text


Compareing two numbers

Enter your first number: 5
Enter your second number: 9
Maximum number: 9
```
**Equal Numbers Example:**
```text


Compareing two numbers

Enter your first number: 7
Enter your second number: 7
[ERROR] Numbers are equal.
```
**Invalid Input Error Example:**
```text


Compareing two numbers

Enter your first number: x
[ERROR] Invalid input for first number.
```