# Compare Two Times

A simple C program demonstrating custom structure definition (`struct`), standard input processing, range validation, and time comparison logic.

## Description

This program defines a custom `struct Time` to encapsulate integer `hour` and `minute` properties. It prompts the user to enter two separate time values from standard input (`stdin`), validates that valid numeric values were provided for hours (0–23) and minutes (0–59), and compares the two timestamps. It then outputs whether the first time is later than, equal to, or earlier than the second time, formatted in standard `HH:MM` format.

## Features

- Custom C structure encapsulation (`struct Time`).
- Interactive command-line prompts for two pairs of hours and minutes.
- Input validation catching non-numeric entries and out-of-bounds time values (`0 <= hour <= 23` and `0 <= minute <= 59`).
- Two-tier time comparison logic evaluating hours first, followed by minutes.
- Formatted zero-padded time output (`%02d:%02d`).
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
./compare_times
```

## Usage Examples

**First Time Later Example:**

```text
=== Compare Two Times ===

Enter hours of first time: 14
Enter minutes of first time: 30

Enter hours of second time: 09
Enter minutes of second time: 15

[INFO] 14:30 is later than 09:15.
```

**Equal Times Example:**

```text
=== Compare Two Times ===

Enter hours of first time: 10
Enter minutes of first time: 45

Enter hours of second time: 10
Enter minutes of second time: 45

[INFO] 10:45 equals 10:45.
```

**Second Time Later Example:**

```text
=== Compare Two Times ===

Enter hours of first time: 08
Enter minutes of first time: 00

Enter hours of second time: 12
Enter minutes of second time: 30

[INFO] 12:30 is later than 08:00.
```

**Invalid Time Range Error Example:**

```text
=== Compare Two Times ===

Enter hours of first time: 25
Enter minutes of first time: 10
Enter hours of second time: 10
Enter minutes of second time: 00
[ERROR] Invalid time. Use HH:MM format.
```

**Invalid Input Type Example:**

```text
=== Compare Two Times ===

Enter hours of first time: abc
[ERROR] Invalid hour.
```