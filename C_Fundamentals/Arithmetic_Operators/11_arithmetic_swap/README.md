# Arithmetical Swap

A simple C program demonstrating standard input handling, input validation, and variable swapping using basic arithmetic operations.

## Description

This program prompts the user to enter two integers from standard input (`stdin`). It validates both inputs to ensure valid numeric data is provided, calculates their sum, and uses arithmetic subtraction to output the swapped values of the two numbers.

## Features

- Interactive command-line prompts for two integer inputs.
- Comprehensive input validation catching non-numeric input.
- Value swapping via arithmetic addition and subtraction operations.
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
./arithmetical_swap
```

## Usage Examples

**Valid Input Example:**

```text
Arithmetical Swap

Enter your first number: 10
Enter your second number: 25

Changed first number: 25
Changed second number: 10
```

**Negative Numbers Example:**

```text
Arithmetical Swap

Enter your first number: -5
Enter your second number: 12

Changed first number: 12
Changed second number: -5
```

**Invalid Input Example:**

```text
Arithmetical Swap

Enter your first number: abc
Error: Invalid input. Please enter an integer.
```