# Rectangle Perimeter Calculator

A simple C program demonstrating standard input handling, non-negativity validation, and integer overflow protection using `<limits.h>` to compute the perimeter of a rectangle.

## Description

This program prompts the user to enter the length and width of a rectangle from standard input (`stdin`). It validates both inputs to ensure valid numeric data, checks that neither dimension is negative, and guards against potential `INT_MAX` overflow before calculating and displaying the perimeter (`2 * (length + width)`).

## Features

- Interactive command-line prompt for length and width.
- Input validation for integer inputs.
- Non-negativity checks (`length >= 0` and `width >= 0`).
- Safe arithmetic overflow detection using `INT_MAX`.
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
./rectangle_perimeter
```

## Usage Examples

**Valid Input Example:**

```text
Rectangle perimeter

Enter length: 10
Enter width: 5

Perimeter: 30
```

**Negative Input Error Example:**

```text
Rectangle perimeter

Enter length: -5
Enter width: 10
Error: Length and width cannot be negative.
```

**Integer Overflow Error Example:**

```text
Rectangle perimeter

Enter length: 1100000000
Enter width: 1000000000
Error: Rectangle perimeter is too large.
```

**Invalid Input Example:**

```text
Rectangle perimeter

Enter length: abc
Error: Invalid input. Please enter a valid integer.
```