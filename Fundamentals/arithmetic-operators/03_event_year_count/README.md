# Event Year Count

A simple C program demonstrating standard console input and output handling, integer arithmetic, and basic input validation to calculate the difference between two years.

## Description

This program prompts the user to enter the present year and an event year from standard input (`stdin`). It validates both inputs to ensure valid integer values are provided, computes the difference (`present_year - event_year`), and outputs the elapsed or remaining years.

## Features

- Interactive command-line prompt for present and event years.
- Input validation to catch non-integer values.
- Integer subtraction calculation for elapsed time.
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
./event_year_count
```

## Usage Examples

**Past Event Example:**

```text
Event year count

Write present year: 2026
Write event year: 1969

Difference: 57 years
```

**Future Event Example:**

```text
Event year count

Write present year: 2026
Write event year: 2030

Difference: -4 years
```

**Invalid Input Example:**

```text
Event year count

Write present year: abc
Error: Invalid input. Please enter a valid year.
```