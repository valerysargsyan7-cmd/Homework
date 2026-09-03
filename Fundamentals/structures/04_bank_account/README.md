# Bank Account Simulator

A C program demonstrating structure encapsulation (`struct`), interactive standard input handling, non-negativity validation, continuous loop processing (`while(1)`), and dynamic balance calculation.

## Description

This program defines a custom `struct BankAccount` to maintain a floating-point `balance`. It prompts the user for an initial starting balance, validates that it is non-negative, and enters an interactive withdrawal loop. Within the loop, users can repeatedly withdraw funds, exit by entering `0`, or receive error messages for invalid entries or insufficient funds.

## Features

- Custom C structure encapsulation (`struct BankAccount`).
- Interactive CLI menu allowing repeated withdrawal operations (`while(1)` loop).
- Dynamic balance updating and non-negative amount validation.
- Error handling for invalid input formats, negative amounts, and insufficient funds.
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
./bank_account
```

## Usage Examples

**Successful Withdrawal Example:**

```text
=== Bank Account ===

Enter your balance: 500.00

How much money do you want to take? (0 to exit): 150.50

[SUCCESS] Withdrawn: 150.50
[INFO] Remaining balance: 349.50

How much money do you want to take? (0 to exit): 0

[INFO] Operation finished.
```

**Insufficient Funds Example:**

```text
=== Bank Account ===

Enter your balance: 100.00

How much money do you want to take? (0 to exit): 150.00
[ERROR] Insufficient funds.
```

**Negative Input Error Example:**

```text
=== Bank Account ===

Enter your balance: 200.00

How much money do you want to take? (0 to exit): -50
[ERROR] Amount cannot be negative.

How much money do you want to take? (0 to exit): 0

[INFO] Operation finished.
```