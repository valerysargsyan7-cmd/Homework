# Fibonacci
A C program demonstrating recursion to compute the nth Fibonacci number.
## Description
This program prompts the user to enter a non-negative integer `n` via standard input (`stdin`). It computes the nth Fibonacci number recursively — a `fibonacci` function that calls itself with `n-1` and `n-2` until it reaches the base cases of 0, 1, or 2 — and prints the result.
## Features
- Recursive computation of the Fibonacci sequence via self-calling function.
- Base case handling for `0` (returns `0`) and `1`/`2` (both return `1`).
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
./fibonacci
```
## Usage Examples
**Fibonacci Example:**
```text


Fibonacci


Enter number for Fibonacci: 10

10 number's Fibonacci is: 55
```
**Negative Index Error Example:**
```text


Fibonacci


Enter number for Fibonacci: -3
[ERROR] Fibonacci index cannot be negative!
```
**Invalid Input Error Example:**
```text


Fibonacci


Enter number for Fibonacci: x
[ERROR] Invalid input!
```