# Month Day Combination Checker

A simple C program demonstrating standard input processing, input validation, and calendar logic to check whether a given day and month combination is valid in a standard non-leap year.

## Description

This program prompts the user to enter a day and a month as integers from standard input (`stdin`). It validates both inputs for integer correctness and evaluates whether the day is valid for the given month. Month bounds (1–12) and day counts (28 days for February, 30 days for April, June, September, November, and 31 days for remaining months) are strictly checked. It outputs "VALID" for legitimate calendar dates and "INVALID" otherwise.

## Features

- Interactive command-line prompts for day and month inputs.
- Input validation catching non-numeric entries.
- Calendar logic validating days per month for non-leap years.
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
./month_day_check
```

## Usage Examples

**Valid Date Example:**

```text
Checking month day combination

Enter day: 25
Enter month: 12

VALID
```

**Invalid Date Example (April 31st):**

```text
Checking month day combination

Enter day: 31
Enter month: 4

INVALID
```

**Invalid Month Range Example:**

```text
Checking month day combination

Enter day: 15
Enter month: 13

INVALID
```

**Invalid Input Type Example:**

```text
Checking month day combination

Enter day: abc
Error: Invalid day.
```