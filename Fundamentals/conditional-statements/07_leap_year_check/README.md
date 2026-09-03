# Leap Year Checker

A C program demonstrating standard input handling, input validation, range checking, and compound boolean logic to determine if a given year is a leap year.

## Description

This program prompts the user to enter a positive integer representing a year from standard input (`stdin`). It validates that the input is a valid integer greater than zero and applies Gregorian calendar leap year rules (`(year % 4 == 0 && year % 100 != 0) || year % 400 == 0`) to determine whether the specified year is a leap year.

## Features

- Interactive command-line prompt for year entry.
- Input validation to catch non-integer values.
- Range validation ensuring the year is strictly positive (`year > 0`).
- Implementation of standard Gregorian leap year calculation rules.
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
./leap_year
```

## Usage Examples

**Leap Year Example:**

```text
Leap year

Enter year: 2024

The year is a leap year
```

**Common Year Example:**

```text
Leap year

Enter year: 2023

The year is not a leap year
```

**Century Non-Leap Year Example:**

```text
Leap year

Enter year: 1900

The year is not a leap year
```

**Invalid Year Value Example:**

```text
Leap year

Enter year: 0
Error: Year must be greater than zero.
```

**Invalid Input Example:**

```text
Leap year

Enter year: abc
Error: Invalid input. Please enter a valid integer.
```