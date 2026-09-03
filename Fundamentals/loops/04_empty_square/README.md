# Empty Square Pattern

A C program demonstrating nested `for` loops, conditional logic for border detection, character input handling using `scanf`, and terminal pattern rendering.

## Description

This program prompts the user to enter a positive integer for the square size and a character symbol to draw the border. It validates that the size is positive and the character input is correctly read. Using nested loops, it prints an hollow (empty) square of the specified size where only the outer perimeter is drawn using the user's symbol and the interior is filled with spaces.

## Features

- Interactive console prompts for size and border symbol.
- Input validation for numeric size and single character input.
- Border conditional check evaluating boundary conditions (`i == 0`, `i == quantity - 1`, `j == 0`, or `j == quantity - 1`).
- Clean hollow pattern printing to standard output (`stdout`).
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
./empty_square
```

## Usage Examples

**Hollow Square Example:**

```text
=== Empty Square ===

Enter square size: 5
Enter symbol for the square: *
*****
*   *
*   *
*   *
*****
```

**Invalid Size Error Example:**

```text
=== Empty Square ===

Enter square size: -2
[ERROR] Square size must be positive.
```

**Non-Numeric Input Error Example:**

```text
=== Empty Square ===

Enter square size: abc
[ERROR] Invalid square size.
```