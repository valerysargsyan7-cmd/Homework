# Factorial Calculator

A simple C program demonstrating standard console input processing, non-negativity validation, and `for` loop iteration to calculate the factorial of an integer.

## Description

This program prompts the user for a non-negative integer via standard input (`stdin`). It validates that valid numeric input was provided and ensures the number is non-negative, as factorials are undefined for negative values. It then uses an iterative `for` loop to compute the factorial of the specified number and displays the result.

## Features

- Interactive command-line prompt for integer input.
- Input validation catching non-numeric entries.
- Non-negativity check ensuring the entered integer is greater than or equal to 0.
- Iterative factorial computation using a `for` loop.
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

**Standard Factorial Example:**

```text
=== Factorial Calculator ===

Enter your number: 5

[SUCCESS] Factorial of 5 is: 120
```

**Zero Input Example:**

```text
=== Factorial Calculator ===

Enter your number: 0

[SUCCESS] Factorial of 0 is: 1
```

**Negative Input Error Example:**

```text
=== Factorial Calculator ===

Enter your number: -3
[ERROR] Factorial is not defined for negative numbers.
```

**Invalid Input Type Example:**

```text
=== Factorial Calculator ===

Enter your number: abc
[ERROR] Invalid input.
```