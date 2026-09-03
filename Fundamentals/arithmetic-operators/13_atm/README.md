# ATM Banknote Dispenser

A simple C program demonstrating standard console input processing, non-negativity checks, greedy denomination breakdown, and divisibility validation for Armenian Dram banknote dispensing.

## Description

This program prompts the user to enter a requested monetary amount from standard input (`stdin`). It validates that a valid integer is supplied, checks that the amount is non-negative, and determines the breakdown of standard Armenian Dram banknotes (10,000 AMD, 5,000 AMD, and 1,000 AMD) using a greedy algorithm with integer division and modulo operations. If the requested amount is not divisible by the smallest denomination (1,000 AMD), the program reports an error.

## Features

- Interactive command-line prompt for currency withdrawal amount.
- Input validation catching non-numeric inputs.
- Non-negativity check (`money_requested >= 0`).
- Greedy denomination calculation for 10,000 AMD, 5,000 AMD, and 1,000 AMD banknotes.
- Denomination validity enforcement (ensures amount is divisible by 1000).
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
./atm
```

## Usage Examples

**Valid Withdrawal Example:**

```text
ATM

How much money do you want?: 26000

2 times 10000, 1 times 5000, 1 times 1000
```

**Exact Denomination Example:**

```text
ATM

How much money do you want?: 50000

5 times 10000, 0 times 5000, 0 times 1000
```

**Invalid Denomination Error Example:**

```text
ATM

How much money do you want?: 2500
Error: Amount must be divisible by 1000.
```

**Negative Input Error Example:**

```text
ATM

How much money do you want?: -1000
Error: Requested money cannot be negative.
```

**Invalid Input Type Example:**

```text
ATM

How much money do you want?: abc
Error: Invalid input. Please enter an integer.
```