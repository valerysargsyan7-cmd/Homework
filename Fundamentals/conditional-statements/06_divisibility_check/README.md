# Divisibility Check

A C program demonstrating console input validation, division-by-zero checks, and logical conjunction (`&&`) with modulo operations to determine whether a target number is simultaneously divisible by two divisors.

## Description

This program prompts the user to input a target integer along with two potential divisor integers from standard input (`stdin`). It validates each entry to ensure valid integer input and checks that neither divisor is zero. Upon successful input validation, it verifies whether the target number is divisible by both specified divisors using the modulo operator (`%`) combined with logical AND (`&&`).

## Features

- Interactive command-line prompt for target number and two divisors.
- Input validation catching non-integer values for all inputs.
- Guard against division by zero for both specified divisors.
- Compound logical condition testing simultaneous divisibility.
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
./divisibility_check
```

## Usage Examples

**Divisible by Both Divisors Example:**

```text
Divisibility check

Enter the number to check: 12
Enter the first divisor: 3
Enter the second divisor: 4

Number 12 is divisible by both 3 and 4
```

**Not Divisible by Both Divisors Example:**

```text
Divisibility check

Enter the number to check: 10
Enter the first divisor: 2
Enter the second divisor: 3

Number 10 is NOT divisible by both 2 and 3
```

**Division by Zero Error Example:**

```text
Divisibility check

Enter the number to check: 15
Enter the first divisor: 0
Enter the second divisor: 5
Error: Division by zero is not allowed.
```

**Invalid Input Example:**

```text
Divisibility check

Enter the number to check: abc
Error: Invalid input. Please enter a valid integer.
```