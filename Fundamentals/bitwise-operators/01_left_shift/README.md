# Dynamic Left Shift Calculation

A C program demonstrating standard input handling, bitwise left-shift operations, and boundary validation for user-defined shift counts.

## Description

This program prompts the user to enter an unsigned integer and a dynamic shift count from standard input (`stdin`). It validates both inputs to ensure valid numeric values and checks whether the shift count falls within the allowable bit range for the integer type (`0` to `sizeof(unsigned int) * 8 - 1`). Upon successful validation, it computes and displays the left-shift result (`number << shift_count`).

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
./dynamic_left_shift
```

## Usage Examples

**Valid Input Example:**

```text
Left shifting
Enter your number: 5
Enter shift count (0 - 31): 2
Result: 20
```

**Out of Range Shift Count Example:**

```text
Left shifting
Enter your number: 5
Enter shift count (0 - 31): 32
Error: Shift count is out of range.
```

**Invalid Input Example:**

```text
Left shifting
Enter your number: abc
Error: Invalid input. Please enter a valid unsigned integer.
```