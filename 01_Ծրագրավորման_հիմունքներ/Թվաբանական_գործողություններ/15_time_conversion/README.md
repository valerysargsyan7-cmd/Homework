# Time Converter

A simple C program demonstrating standard console input processing, non-negativity validation, time arithmetic, and formatted output (`HH:MM:SS`).

## Description

This program prompts the user to enter a duration in total seconds from standard input (`stdin`). It validates that the input is a non-negative integer and converts the total seconds into hours, minutes, and remaining seconds using integer division and modulo operations. The formatted output is printed using two-digit zero padding (`%02d`).

## Features

- Interactive command-line prompt for total seconds input.
- Input validation for numeric integrity and non-negativity (`seconds >= 0`).
- Mathematical conversion:
  - Hours: `seconds / 3600`
  - Minutes: `(seconds / 60) % 60`
  - Remaining seconds: `seconds % 60`
- Zero-padded time formatting (`HH:MM:SS`).
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
./time_converter
```

## Usage Examples

**Standard Conversion Example:**

```text
Time converting

Enter seconds: 3661

01:01:01
```

**Zero Seconds Example:**

```text
Time converting

Enter seconds: 0

00:00:00
```

**Negative Input Error Example:**

```text
Time converting

Enter seconds: -45
Error: Seconds cannot be negative.
```

**Invalid Input Type Example:**

```text
Time converting

Enter seconds: abc
Error: Invalid input. Please enter an integer.
```