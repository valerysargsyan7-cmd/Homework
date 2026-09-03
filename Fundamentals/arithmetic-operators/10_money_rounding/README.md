# Shop Money (Currency Rounding Calculator)

A simple C program demonstrating standard double-precision floating-point input processing, non-negativity validation, and standard half-up rounding using integer casting.

## Description

This program prompts the user to enter a monetary amount as a floating-point number (`double`) from standard input (`stdin`). It validates that a valid numeric input is provided and checks that the value is non-negative. It then rounds the amount to the nearest whole integer using standard half-up rounding logic (`(long long)(money + 0.5)`) and prints the result.

## Features

- Interactive command-line prompt for monetary input.
- Input validation catching non-numeric values.
- Non-negativity check (`money >= 0.0`).
- Half-up rounding logic using floating-point addition and integer casting.
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
./shop_money
```

## Usage Examples

**Rounding Up Example:**

```text
Shop money

Enter money: 12.5

Rounded: 13
```

**Rounding Down Example:**

```text
Shop money

Enter money: 12.49

Rounded: 12
```

**Negative Input Error Example:**

```text
Shop money

Enter money: -5.75
Error: Money cannot be negative.
```

**Invalid Input Example:**

```text
Shop money

Enter money: abc
Error: Invalid input. Please enter a valid amount.
```