# Odd or Even (Bitwise Parity Checker)

A simple C program demonstrating standard console input processing, input validation, and bitwise AND (`&`) operations to determine integer parity (odd or even).

## Description

This program prompts the user to enter an integer from standard input (`stdin`). It validates the input to ensure a valid integer value is provided, performs a bitwise AND operation with `1` (`number & 1`) to inspect the least significant bit, and outputs "ODD" if the bit is set or "EVEN" if it is cleared.

## Features

- Interactive command-line prompt for integer entry.
- Comprehensive input validation catching non-numeric inputs.
- Fast parity checking using bitwise AND (`number & 1`).
- Support for positive, negative, and zero integer inputs.
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
./odd_or_even
```

## Usage Examples

**Odd Integer Example:**

```text
Odd or even

Enter your number: 7

ODD
```

**Even Integer Example:**

```text
Odd or even

Enter your number: 12

EVEN
```

**Negative Odd Integer Example:**

```text
Odd or even

Enter your number: -5

ODD
```

**Invalid Input Example:**

```text
Odd or even

Enter your number: abc
Error: Invalid input. Please enter a valid integer.
```