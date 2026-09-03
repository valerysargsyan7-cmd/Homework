# Divide Odd Number by Two

A simple C program demonstrating input validation, odd number checking via modulo arithmetic, and floating-point division.

## Description

This program prompts the user to enter an odd integer from standard input (`stdin`). It validates that the input is a valid integer and checks that the number is strictly odd using the modulo operator (`number % 2 != 0`). Upon successful validation, it divides the odd integer by `2.0f` to calculate the exact half value and displays the result formatted to two decimal places.

## Features

- Interactive command-line prompt for integer entry.
- Input validation to catch non-integer values.
- Odd number verification (`number % 2 != 0`).
- Floating-point division to preserve fractional results.
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
./divide_odd
```

## Usage Examples

**Valid Odd Number Example:**

```text
Divide odd number by two

Enter your odd number: 7

Result: 3.50
```

**Even Number Error Example:**

```text
Divide odd number by two

Enter your odd number: 4
Error: The number must be odd.
```

**Invalid Input Example:**

```text
Divide odd number by two

Enter your odd number: abc
Error: Invalid input. Please enter a valid integer.
```