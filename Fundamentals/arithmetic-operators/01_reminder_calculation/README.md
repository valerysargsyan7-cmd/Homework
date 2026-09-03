# Remainder Calculation

A simple C program demonstrating standard input handling and input validation while performing a modulo (remainder) operation on two integers.

## Description

This program prompts the user to enter two integers from the standard input (`stdin`). It validates both inputs to ensure valid numeric data is received, checks against division by zero, and calculates the remainder of the division between the first and second number.

## Features

- Interactive command-line prompt for two numbers.
- Input validation to catch non-integer inputs.
- Guard check against division by zero.
- Standard C compliant implementation.

## Requirements

- C Compiler (`gcc` or `clang`)

## Compilation

Build the program using GCC:

```bash
gcc -Wall -Wextra -std=c11 main.c -o remainder_calc
```

## Running

Run the compiled executable:

```bash
./remainder_calc
```

## Usage Examples

**Valid Input Example:**

```text
Remainder calculation
Enter first number: 10
Enter second number: 3
Remainder: 1
```

**Division by Zero Example:**

```text
Remainder calculation
Enter first number: 10
Enter second number: 0
Error: Division by zero is not allowed.
```

**Invalid Input Example:**

```text
Remainder calculation
Enter first number: abc
Error: Invalid input. Please enter a valid integer.
```