# Even or Odd Checker

A simple C program demonstrating standard console input handling, input validation, and parity checking using modulo arithmetic.

## Description

This program prompts the user to enter an integer from standard input (`stdin`). It validates the input to ensure a valid numeric value is provided and then checks whether the integer is even or odd using the modulo operator (`number % 2`).

## Features

- Interactive command-line prompt.
- Input validation to catch non-integer inputs.
- Parity detection logic (`even` / `odd`).
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
./even_checker
```

## Usage Examples

**Even Number Example:**

```text
Check even

Enter your number: 4

Number is even
```

**Odd Number Example:**

```text
Check even

Enter your number: 7

Number is odd
```

**Invalid Input Example:**

```text
Check even

Enter your number: abc
Error: Invalid input. Please enter a valid integer.
```