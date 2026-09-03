# Classify Check

A simple C program demonstrating standard console input handling, input validation, arithmetic summation, and threshold comparison logic.

## Description

This program prompts the user to enter three integers from standard input (`stdin`). It validates each input to ensure valid numeric data is provided, calculates their sum, and checks whether the total sum is greater than, less than, or exactly equal to 100.

## Features

- Interactive command-line prompt for three integer values.
- Input validation to catch non-integer inputs for each entry.
- Summation calculation and threshold comparison (`result > 100`, `result < 100`, `result == 100`).
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
./sum_check
```

## Usage Examples

**Large Sum Example (> 100):**

```text
Sum check

Enter first number: 40
Enter second number: 40
Enter third number: 30

Large sum
```

**Small Sum Example (< 100):**

```text
Sum check

Enter first number: 10
Enter second number: 20
Enter third number: 30

Small sum
```

**Exactly 100 Example:**

```text
Sum check

Enter first number: 50
Enter second number: 30
Enter third number: 20

Sum is exactly 100
```

**Invalid Input Example:**

```text
Sum check

Enter first number: abc
Error: Invalid input. Please enter a valid integer.
```