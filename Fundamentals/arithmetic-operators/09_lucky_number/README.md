# Lucky Number Calculating

A simple C program demonstrating standard input validation, digit extraction via integer division and modulo arithmetic, and conditional logic to check for lucky numbers.

## Description

This program prompts the user to enter a four-digit integer from standard input (`stdin`). It validates that the input is a valid integer and strictly falls within the range of 1000 to 9999. It then extracts individual digits (thousands, hundreds, tens, and units) using division and modulo operations. If the sum of the first two digits equals the sum of the last two digits (`thousands + hundreds == tens + units`), the program outputs "LUCKY"; otherwise, it outputs "UNLUCKY".

## Features

- Interactive command-line prompt for a four-digit integer entry.
- Comprehensive input validation ensuring numeric input and exactly four digits (`1000 <= number <= 9999`).
- Individual digit extraction using integer division and modulo arithmetic (`/ 1000`, `/ 100 % 10`, `/ 10 % 10`, `% 10`).
- Parity sum comparison to evaluate "lucky" status.
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
./lucky_number
```

## Usage Examples

**Lucky Number Example:**

```text
Lucky number calculating

Enter your four-digit number: 3728

LUCKY
```

**Unlucky Number Example:**

```text
Lucky number calculating

Enter your four-digit number: 1234

UNLUCKY
```

**Invalid Digit Length Error Example:**

```text
Lucky number calculating

Enter your four-digit number: 456
Error: Number must contain exactly four digits.
```

**Invalid Input Example:**

```text
Lucky number calculating

Enter your four-digit number: abc
Error: Invalid input. Please enter a valid integer.
```