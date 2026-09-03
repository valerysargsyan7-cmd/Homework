# Positive or Negative Checker

A simple C program demonstrating standard input handling, input validation, and conditional checks to classify an integer as positive, negative, or zero.

## Description

This program prompts the user to enter an integer from standard input (`stdin`). It validates the input to ensure a valid numeric value is provided and then checks whether the integer is positive, negative, or zero.

## Features

- Interactive command-line prompt for an integer value.
- Input validation to catch non-integer inputs.
- Three-way conditional check (`positive`, `negative`, `zero`).
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
./pos_neg_checker
```

## Usage Examples

**Positive Number Example:**

```text
Positive or negative

Enter your number: 5

Number is positive
```

**Negative Number Example:**

```text
Positive or negative

Enter your number: -3

Number is negative
```

**Zero Example:**

```text
Positive or negative

Enter your number: 0

Number is zero
```

**Invalid Input Example:**

```text
Positive or negative

Enter your number: abc
Error: Invalid input. Please enter a valid integer.
```