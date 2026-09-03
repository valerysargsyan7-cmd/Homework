# Positive / Zero / Negative

A C program demonstrating array storage, interactive console input processing with validation, `for` loop iteration, and conditional branching to classify integers.

## Description

This program prompts the user to enter 10 integer values sequentially via standard input (`stdin`). It stores each value in an array (`numbers[10]`) while performing input validation. For each entered number, it uses conditional `if-else if-else` branching to evaluate whether the value is strictly positive, zero, or negative, printing a corresponding notification message.

## Features

- Array storage for 10 sequential integer inputs.
- Interactive per-element console input prompts and validation.
- Conditional classification checking (`> 0`, `== 0`, and `< 0`).
- Error handling for invalid or non-numeric inputs.
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
./positive_zero_negative
```

## Usage Examples

**Classification Example:**

```text
=== Positive / Zero / Negative ===

Enter number 1: 5

[INFO] 5 is positive.
Enter number 2: 0

[INFO] 0 is zero.
Enter number 3: -3

[INFO] -3 is negative.
```

**Invalid Input Error Example:**

```text
=== Positive / Zero / Negative ===

Enter number 1: abc
[ERROR] Invalid number.
```