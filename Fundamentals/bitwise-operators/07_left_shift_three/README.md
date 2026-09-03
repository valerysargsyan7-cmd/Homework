# Shifting (Bitwise Left Shift)

A simple C program demonstrating unsigned integer input processing, shift boundary verification, and bitwise left-shift operations (`<<`).

## Description

This program prompts the user to enter an unsigned integer from standard input (`stdin`). It validates that a valid unsigned numeric value is entered and checks that the constant bitwise shift count (`shift_count = 3U`) is within the bit-width capacity of the unsigned integer type (`sizeof(number) * 8U`). Upon validation, it performs a bitwise left shift by 3 bits (`number << 3U`) and displays the calculated result.

## Features

- Interactive command-line prompt for unsigned integer entry.
- Comprehensive input validation catching non-numeric input types.
- Shift boundary check preventing undefined behavior from shifting equal to or exceeding data type bit-width.
- Bitwise left-shift calculation (`<<`).
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
./shifting
```

## Usage Examples

**Valid Input Example:**

```text
Shifting

Enter number: 5

Result: 40
```

**Zero Input Example:**

```text
Shifting

Enter number: 0

Result: 0
```

**Invalid Input Example:**

```text
Shifting

Enter number: abc
Error: Invalid input. Please enter a valid unsigned integer.
```