# Comparing Numbers (Maximum Finder)

A simple C program demonstrating standard console input handling, input validation, and sequential conditional comparisons to find the maximum among three integers.

## Description

This program prompts the user to enter three integers from standard input (`stdin`). It validates each input to ensure valid integer values are provided, initializes the maximum value to the first integer, and sequentially compares it against the second and third integers to determine and output the maximum value.

## Features

- Interactive command-line prompt for three integer inputs.
- Input validation to catch non-integer entries.
- Sequential comparison logic to track maximum value.
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
./max_finder
```

## Usage Examples

**Distinct Numbers Example:**

```text
Comparing numbers

Enter first number: 10
Enter second number: 45
Enter third number: 23

Maximum: 45
```

**Negative Numbers Example:**

```text
Comparing numbers

Enter first number: -15
Enter second number: -3
Enter third number: -8

Maximum: -3
```

**Invalid Input Example:**

```text
Comparing numbers

Enter first number: abc
Error: Invalid input. Please enter a valid integer.
```