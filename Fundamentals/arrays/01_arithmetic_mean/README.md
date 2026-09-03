# Arithmetic Mean Calculator

A simple C program demonstrating array initialization, iterative loop traversal, type casting, and arithmetic mean calculation.

## Description

This program initializes a fixed-size integer array containing 10 elements (1 through 10). It iterates through the array using a `for` loop to accumulate the sum of all elements. It then computes the arithmetic mean by explicitly casting the integer sum to a `float` prior to division by the total element count, outputting the result rounded to two decimal places.

## Features

- Fixed-size integer array initialization.
- Iterative sum calculation using a `for` loop.
- Explicit type casting `(float)` to prevent integer division truncating precision.
- Formatted output displaying the calculated mean to two decimal places (`%.2f`).
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
./arithmetic_mean
```

## Usage Examples

**Execution Example:**

```text
=== Arithmetic Mean ===


[SUCCESS] Arithmetic mean: 5.50
```