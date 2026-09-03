# Recursive Factorial
A C program demonstrating recursion, using a `long long` return type to correctly compute factorials larger than a plain `int` can hold.
## Description
This program prompts the user to enter an integer via standard input (`stdin`), validating that it is not negative. It then computes the factorial recursively — a `factorial` function that calls itself with a decremented argument until it reaches the base case of 0 or 1 — returning a `long long` to accommodate results too large for `int`, and prints the result.
## Features
- Recursive computation of factorial via self-calling function.
- Base case handling for `0` and `1` (both return `1`).
- `long long` return type to correctly represent factorials up to 20! without overflow.
- Validation rejecting negative input.
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
./factorial
```
## Usage Examples
**Factorial Example:**
```text


Recursive Factorial


Enter number for factorial: 13

Factorial of this number 13 is: 6227020800
```
**Negative Number Error Example:**
```text


Recursive Factorial


Enter number for factorial: -3
[ERROR] Factorial cannot be calculated for a negative number!
```
**Invalid Input Error Example:**
```text


Recursive Factorial


Enter number for factorial: x
[ERROR] Invalid input!
```