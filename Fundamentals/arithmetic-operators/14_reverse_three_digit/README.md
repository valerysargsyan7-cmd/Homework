# Reversing Three-Digit Number

A simple C program demonstrating standard input processing, range validation, integer digit decomposition, and output formatting to reverse a three-digit integer.

## Description

This program prompts the user to enter a positive three-digit integer from standard input (`stdin`). It validates that the input is a valid integer strictly within the range of 100 to 999. It then extracts individual digits (hundreds, tens, and units) using integer division and modulo arithmetic (`/ 100`, `/ 10 % 10`, `% 10`) and prints them in reverse order.

## Features

- Interactive command-line prompt for a three-digit integer.
- Strict input validation checking numeric format and integer range (`100 <= number <= 999`).
- Digit decomposition using integer division and modulo operations.
- Direct output formatting of reversed digits.
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
./reverse_three_digits
```

## Usage Examples

**Valid Input Example:**

```text
Reversing three-digit number

Enter your number: 123

Reversed number: 321
```

**Trailing Zero Digit Example:**

```text
Reversing three-digit number

Enter your number: 500

Reversed number: 005
```

**Out of Range Error Example:**

```text
Reversing three-digit number

Enter your number: 45
Error: Number must contain exactly three digits.
```

**Invalid Input Type Example:**

```text
Reversing three-digit number

Enter your number: abc
Error: Invalid input. Please enter an integer.
```