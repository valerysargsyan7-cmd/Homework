# Find Maximum

A simple C program demonstrating standard console input handling, input validation, and conditional comparison logic to determine the larger of two integers.

## Description

This program prompts the user to enter two integers from standard input (`stdin`). It validates both inputs to ensure valid numeric values are provided and then compares them to determine which number is greater, or if they are equal.

## Features

- Interactive command-line prompt for two integer values.
- Input validation to catch non-integer inputs.
- Three-way comparison logic (`greater than`, `less than`, `equal`).
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
./find_max
```

## Usage Examples

**First Number Greater Example:**

```text
Find maximum

Enter your first number: 20
Enter your second number: 10

First number is bigger than second
```

**Second Number Greater Example:**

```text
Find maximum

Enter your first number: 5
Enter your second number: 15

Second number is bigger than first
```

**Equal Numbers Example:**

```text
Find maximum

Enter your first number: 7
Enter your second number: 7

Numbers are equal
```

**Invalid Input Example:**

```text
Find maximum

Enter your first number: abc
Error: Invalid input. Please enter a valid integer.
```