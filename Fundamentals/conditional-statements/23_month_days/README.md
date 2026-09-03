# Month Days Counter

A simple C program demonstrating standard input processing, input validation, range checking, and conditional branching to determine the number of days in a month for a standard non-leap year.

## Description

This program prompts the user to enter a month number (1–12) from standard input (`stdin`). It validates that the input is a valid integer and checks whether the value falls within the valid range of 1 to 12. If invalid, it outputs "INVALID MONTH". Otherwise, it determines and displays the total number of days in that month:
- **28 days**: February (month 2)
- **30 days**: April (4), June (6), September (9), November (11)
- **31 days**: January (1), March (3), May (5), July (7), August (8), October (10), December (12)

## Features

- Interactive command-line prompt for month number input.
- Input validation catching non-numeric entries.
- Range checking for month values between 1 and 12.
- Calendar logic for standard (non-leap) years.
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
./month_days
```

## Usage Examples

**February Example:**

```text
Month days

Enter month number: 2

Days: 28
```

**30-Day Month Example (April):**

```text
Month days

Enter month number: 4

Days: 30
```

**31-Day Month Example (December):**

```text
Month days

Enter month number: 12

Days: 31
```

**Invalid Month Range Example:**

```text
Month days

Enter month number: 13

INVALID MONTH
```

**Invalid Input Type Example:**

```text
Month days

Enter month number: abc
Error: Invalid input. Please enter an integer.
```