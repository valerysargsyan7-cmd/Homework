# Summing Number Members (Digit Sum Calculator)

A simple C program demonstrating standard console input validation, range checking, integer arithmetic decomposition, and digit summation.

## Description

This program prompts the user to enter a positive three-digit integer from standard input (`stdin`). It validates that the input is a valid numeric integer and falls strictly within the range of 100 to 999. It then decomposes the number into its individual digits (hundreds, tens, and units) using integer division and modulo arithmetic, calculates their sum, and prints the result.

## Features

- Interactive command-line prompt for a three-digit integer.
- Comprehensive input validation ensuring valid integer input and strict 3-digit range (`100 <= number <= 999`).
- Digit extraction using integer division and modulo operations (`/ 100`, `/ 10 % 10`, `% 10`).
- Summation of extracted digits.
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
./digit_sum
```

## Usage Examples

**Valid Input Example:**

```text
Summing number members

Enter a three-digit number: 456

Sum of members: 15
```

**Out of Range Error Example:**

```text
Summing number members

Enter a three-digit number: 88
Error: Number must contain exactly three digits.
```

**Invalid Input Type Example:**

```text
Summing number members

Enter a three-digit number: abc
Error: Invalid input. Please enter an integer.
```