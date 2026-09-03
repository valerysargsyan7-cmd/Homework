# Sum Of Digits
A C program demonstrating recursion to compute the sum of a number's digits.
## Description
This program prompts the user to enter an integer via standard input (`stdin`). It computes the sum of its digits recursively — a `sum_of_digits` function that extracts the last digit via modulo, calls itself with the remaining digits, and adds the results — treating negative numbers as their absolute value. The result is then printed.
## Features
- Recursive digit summation via modulo and division.
- Handling of negative numbers by summing the digits of their absolute value.
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
./sum_of_digits
```
## Usage Examples
**Sum Of Digits Example:**
```text


Sum Of Digits


Enter number for summing digits: 12345

The sum of this number 12345 is: 15
```
**Negative Number Example:**
```text


Sum Of Digits


Enter number for summing digits: -987

The sum of this number -987 is: 24
```
**Invalid Input Error Example:**
```text


Sum Of Digits


Enter number for summing digits: x
[ERROR] Invalid input!
```