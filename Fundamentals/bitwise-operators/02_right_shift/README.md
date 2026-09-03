# Right Shift Calculation

A simple C program demonstrating standard console input and output handling, bitwise right-shift operations, and range validation for user-defined shift counts.

## Description

This program prompts the user to enter an unsigned integer and a shift count from standard input (`stdin`). It validates both inputs to ensure valid numeric values and checks whether the shift count falls within the allowable bit range for the integer type (`0` to `sizeof(unsigned int) * 8 - 1`). Upon successful validation, it computes and displays the right-shift result (`number >> shift_count`).

## Features

- Interactive command-line prompt for both number and shift count.
- Dynamic calculation of maximum allowed bit shift based on system data type size.
- Input validation to catch non-numeric input values.
- Range check to prevent bit-shift overflow beyond type limits.
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
./right_shift
```

## Usage Examples

**Valid Input Example:**

```text
Right shifting
Enter number: 20
Enter your shift count (0 - 31): 2
Result: 5
```

**Out of Range Shift Count Example:**

```text
Right shifting
Enter number: 20
Enter your shift count (0 - 31): 32
Error: Shift count is out of range.
```

**Invalid Input Example:**

```text
Right shifting
Enter number: abc
Error: Invalid input. Please enter a valid unsigned integer.