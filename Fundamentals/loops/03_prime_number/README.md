# Prime Number Check

A simple C program demonstrating standard console input processing, integer validation, and iterative loop logic to determine if a given integer is a prime number.

## Description

This program prompts the user to enter an integer via standard input (`stdin`). It validates that valid numeric input was entered and immediately identifies numbers less than `2` as non-prime. For numbers `2` or greater, it iterates through all integers from `1` to `current_number` using a `for` loop, counting all exact divisors using the modulo operator (`%`). If the total number of divisors equals exactly `2` (1 and the number itself), the program identifies the number as prime.

## Features

- Interactive command-line prompt for integer input.
- Input validation catching non-numeric entries.
- Base condition handling for numbers less than 2.
- Divisor counting via modulo arithmetic (`%`) in a `for` loop.
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
./prime_check
```

## Usage Examples

**Prime Number Example:**

```text
=== Prime Number Check ===

Enter your number: 7

[SUCCESS] Number is prime.
```

**Non-Prime Number Example:**

```text
=== Prime Number Check ===

Enter your number: 9

[INFO] Number is not prime.
```

**Number Less Than 2 Example:**

```text
=== Prime Number Check ===

Enter your number: 1

[INFO] Number is not prime.
```

**Invalid Input Type Example:**

```text
=== Prime Number Check ===

Enter your number: abc
[ERROR] Invalid input.
```