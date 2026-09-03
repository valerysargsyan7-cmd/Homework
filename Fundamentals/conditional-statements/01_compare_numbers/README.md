# Number Comparison

A simple C program demonstrating standard input handling, input validation, and conditional comparison operations between two integers.

## Description

This program prompts the user to enter two integers from standard input (`stdin`). It validates both inputs to ensure valid numeric values are provided and then compares them to check whether they are equal or different.

## Features

- Interactive command-line prompt for two integer values.
- Input validation to catch non-integer inputs.
- Equality comparison logic (`==`).
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
./number_compare
```

## Usage Examples

**Equal Numbers Example:**

```text
Compare two numbers

Enter your first number: 42
Enter your second number: 42

Numbers are equal
```

**Different Numbers Example:**

```text
Compare two numbers

Enter your first number: 10
Enter your second number: 20

Numbers are different
```

**Invalid Input Example:**

```text
Compare two numbers

Enter your first number: abc
Error: Invalid input. Please enter a valid integer.
```