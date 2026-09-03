# Number Members Sum
A C program demonstrating pointer output parameters, digit extraction via modulo/division, and a loop-based summation of a number's digits.
## Description
This program prompts the user to enter an integer via standard input (`stdin`). It passes the number to a `num_mem_summing` function, which sums the individual digits of the number (treating negative numbers as their absolute value) and writes the result through an output pointer. The sum is then printed.
## Features
- Pointer-based output parameter (`sum_ptr`) to return a computed value from a `void` function.
- Digit extraction via modulo and division in a `while` loop.
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
./num_mem_summing
```
## Usage Examples
**Sum Example:**
```text


Number members sum

Enter number: 12345
Sum of members: 15
```
**Negative Number Example:**
```text


Number members sum

Enter number: -123
Sum of members: 6
```
**Invalid Input Error Example:**
```text


Number members sum

Enter number: x
[ERROR] Invalid input. Please enter an integer.
```