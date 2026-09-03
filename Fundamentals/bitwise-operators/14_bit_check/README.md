# Bit Check (3rd Bit Evaluator)

A simple C program demonstrating standard console input processing, input validation, and bitwise AND (`&`) mask checking to determine whether the 3rd bit (bit index 3, weight 8) of an integer is set.

## Description

This program prompts the user to enter an integer from standard input (`stdin`). It validates that a valid integer is supplied and extracts bit index 3 (0-indexed, corresponding to decimal value $2^3 = 8$) using a bitwise AND mask operation (`number & 8`). If the bit is set (non-zero), it outputs "Third bit is one"; otherwise, it outputs "Third bit is zero".

## Features

- Interactive command-line prompt for integer input.
- Input validation catching non-numeric entries.
- Bitwise AND mask checking (`number & 8`).
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
./bit_check
```

## Usage Examples

**Bit Set Example (Bit is 1):**

```text
Bit check

Enter your number: 8

Third bit is one
```

**Bit Unset Example (Bit is 0):**

```text
Bit check

Enter your number: 4

Third bit is zero
```

**Invalid Input Type Example:**

```text
Bit check

Enter your number: abc
Error: Invalid input. Please enter an integer.
```