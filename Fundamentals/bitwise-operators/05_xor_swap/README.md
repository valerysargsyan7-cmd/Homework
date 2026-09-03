# XOR Swapping

A simple C program demonstrating in-place variable swapping using bitwise XOR (`^`) operations and standard input validation.

## Description

This program prompts the user to enter two integers (`a` and `b`) from standard input (`stdin`). It validates both inputs to ensure valid integer values are provided, performs an in-place swap of the two variables using the bitwise XOR swap algorithm without requiring temporary storage, and displays the swapped result.

## Features

- Interactive command-line prompt for two integer variables.
- Input validation catching non-integer inputs.
- In-place value swap using bitwise XOR operations (`a = a ^ b`).
- Memory-efficient variable swapping without auxiliary variables.
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
./xor_swap
```

## Usage Examples

**Valid Swap Example:**

```text
XOR swapping

Enter number of a: 5
Enter number of b: 9

a = 9, b = 5
```

**Identical Numbers Example:**

```text
XOR swapping

Enter number of a: 42
Enter number of b: 42

a = 42, b = 42
```

**Invalid Input Example:**

```text
XOR swapping

Enter number of a: abc
Error: Invalid input. Please enter a valid integer.
```