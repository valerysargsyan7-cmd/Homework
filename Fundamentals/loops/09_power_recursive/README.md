# Power
A C program demonstrating recursion to compute the power of a number raised to a non-negative exponent.
## Description
This program prompts the user to enter a base number and a non-negative exponent via standard input (`stdin`). It computes the result recursively — a `power_of_num` function that multiplies the base by the result of itself called with a decremented exponent, until it reaches the base case of exponent 0 — and prints the result.
## Features
- Recursive computation of exponentiation via self-calling function.
- Base case handling for an exponent of `0` (returns `1`).
- Support for negative base numbers.
- Validation rejecting a negative exponent.
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
./power
```
## Usage Examples
**Power Example:**
```text


Power


Enter number for power: 2

Enter power for number: 10

2 number's 10 power is: 1024
```
**Negative Power Error Example:**
```text


Power


Enter number for power: 2

Enter power for number: -3
[ERROR] Power cannot be negative!
```
**Invalid Input Error Example:**
```text


Power


Enter number for power: x
[ERROR] Invalid number input!
```