# Bitwise
A C program demonstrating a bitwise trick (`n & (n - 1)`) to determine whether a number is a power of two.
## Description
This program prompts the user to enter an integer via standard input (`stdin`). For positive numbers, it checks whether the number is a power of two using the bitwise trick `n & (n - 1) == 0`, which clears the lowest set bit — a result of zero means the original number had exactly one bit set. Zero and negative numbers are treated as not being powers of two. The result is printed as `TRUE` or `FALSE`.
## Features
- Bitwise power-of-two check via `n & (n - 1)`, without loops or division.
- Explicit handling of zero and negative numbers as `FALSE`.
- Error handling for invalid numeric input.
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
./bitwise
```
## Usage Examples
**Power of Two Example:**
```text


Bitwise

Enter number: 16

TRUE
```
**Not a Power of Two Example:**
```text


Bitwise

Enter number: 18

FALSE
```
**Invalid Input Error Example:**
```text


Bitwise

Enter number: x
[ERROR] Invalid input!
```