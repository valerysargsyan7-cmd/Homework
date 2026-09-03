# Multiplication Table
A C program demonstrating a simple `for` loop to print a number's multiplication table from 1 to 10.
## Description
This program prompts the user to enter an integer via standard input (`stdin`). It then prints that number's multiplication table for multipliers 1 through 10, using a `multiplication_table` function.
## Features
- Interactive console input for the base number.
- `for` loop generating the multiplication table from 1 to 10.
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
./multiplication_table
```
## Usage Examples
**Multiplication Table Example:**
```text


Multiplication Table

Enter number: 7

7 * 1 = 7
7 * 2 = 14
7 * 3 = 21
7 * 4 = 28
7 * 5 = 35
7 * 6 = 42
7 * 7 = 49
7 * 8 = 56
7 * 9 = 63
7 * 10 = 70
```
**Invalid Input Error Example:**
```text


Multiplication Table

Enter number: x

[ERROR] Invalid input!
```