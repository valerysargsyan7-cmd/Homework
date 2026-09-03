# Time Calculating (Seconds to HH:MM:SS Converter)

A simple C program demonstrating standard console input handling, non-negativity validation, integer division, and modulo arithmetic to convert total seconds into formatted hours, minutes, and seconds (`HH:MM:SS`).

## Description

This program prompts the user to enter a duration in total seconds from standard input (`stdin`). It validates the input to ensure a non-negative integer is provided, performs integer arithmetic to decompose the input into hours, minutes, and remaining seconds, and prints the result formatted as `HH:MM:SS` with zero-padded 2-digit fields.

## Features

- Interactive command-line prompt for total seconds.
- Comprehensive input validation to catch non-integer and negative inputs.
- Integer division and modulo arithmetic decomposition (`/ 3600`, `% 3600`, `/ 60`, `% 60`).
- Formatted output using `%02d` width specifiers for standard time formatting.
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
./time_calc
```

## Usage Examples

**Valid Input Example:**

```text
Time calculating

Enter seconds: 3661

01:01:01
```

**Zero Seconds Example:**

```text
Time calculating

Enter seconds: 0

00:00:00
```

**Negative Seconds Error Example:**

```text
Time calculating

Enter seconds: -50
Error: Seconds cannot be negative.
```

**Invalid Input Example:**

```text
Time calculating

Enter seconds: abc
Error: Invalid input. Please enter a valid integer.
```