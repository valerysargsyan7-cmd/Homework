# Checking Power of Two

A simple C program demonstrating standard console input validation, positive value checking, and bitwise AND (`&`) operations to verify if an integer is a power of two.

## Description

This program prompts the user to enter an integer from standard input (`stdin`). It validates that a valid integer was supplied and evaluates whether the number is a power of two using the bitwise expression `checking_number > 0 && (checking_number & (checking_number - 1)) == 0`. It outputs "TRUE" if the number is a power of two and "FALSE" otherwise.

## Features

- Interactive command-line prompt for integer input.
- Input validation catching non-numeric inputs.
- Fast power-of-two evaluation using bitwise AND (`n & (n - 1)`).
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
./power_of_two
```

## Usage Examples

**Power of Two Example (True):**

```text
Checking power of two

Enter your number: 16

TRUE
```

**Non-Power of Two Example (False):**

```text
Checking power of two

Enter your number: 18

FALSE
```

**Zero/Negative Input Example (False):**

```text
Checking power of two

Enter your number: 0

FALSE
```

**Invalid Input Type Example:**

```text
Checking power of two

Enter your number: abc
Error: Invalid input. Please enter an integer.
```