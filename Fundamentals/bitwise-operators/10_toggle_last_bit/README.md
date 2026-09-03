# Changing Last Bit (Bitwise LSB Inverter)

A simple C program demonstrating standard console input processing, input validation, and bitwise XOR (`^`) operations to toggle the least significant bit (LSB) of an integer.

## Description

This program prompts the user to enter an integer from standard input (`stdin`). It validates the input to ensure a valid integer is provided, performs a bitwise XOR operation with `1` (`number ^ 1`) to flip the lowest bit (changing even numbers to odd and odd numbers to even), and prints the transformed result.

## Features

- Interactive command-line prompt for integer input.
- Input validation catching non-numeric inputs.
- Least Significant Bit (LSB) bitwise inversion using `number ^ 1`.
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
./change_last_bit
```

## Usage Examples

**Even to Odd Inversion Example:**

```text
Changing last bit

Enter your number: 4

Result: 5
```

**Odd to Even Inversion Example:**

```text
Changing last bit

Enter your number: 7

Result: 6
```

**Invalid Input Example:**

```text
Changing last bit

Enter your number: abc
Error: Invalid input. Please enter a valid integer.
```