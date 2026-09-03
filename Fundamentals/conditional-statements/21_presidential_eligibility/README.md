# Presidential Eligibility (Age Check)

A simple C program demonstrating standard console input processing, non-negativity validation, and boolean flag assignment to evaluate age-based presidential eligibility.

## Description

This program prompts the user to enter their age as an integer from standard input (`stdin`). It validates that a valid integer is supplied, ensures the age is non-negative, and evaluates whether the age meets the minimum requirement for presidential eligibility (`age >= 25`). It stores the result in a boolean variable (`eligible`) and prints the numeric value of the flag (`1` for true/eligible, `0` for false/ineligible).

## Features

- Interactive command-line prompt for age input.
- Input validation catching non-numeric entries.
- Non-negativity validation (`age >= 0`).
- Boolean flag evaluation using `<stdbool.h>` (`eligible = age >= 25`).
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
./presidential_eligibility
```

## Usage Examples

**Eligible Example:**

```text
Presidential eligibility

Enter your age: 30

Eligible: 1
```

**Ineligible Example:**

```text
Presidential eligibility

Enter your age: 20

Eligible: 0
```

**Negative Age Error Example:**

```text
Presidential eligibility

Enter your age: -5
Error: Age cannot be negative.
```

**Invalid Input Type Example:**

```text
Presidential eligibility

Enter your age: abc
Error: Invalid input. Please enter an integer.
```