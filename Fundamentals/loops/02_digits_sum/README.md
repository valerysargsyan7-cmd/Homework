# Sum of Digits

A simple C program demonstrating interactive standard input handling, continuous loop processing (`while(1)`), absolute value conversion for negative integers, and digit extraction using arithmetic division and modulo operations.

## Description

This program repeatedly prompts the user to enter an integer via standard input (`stdin`). Entering `0` terminates the loop. For non-zero integers, the program converts the value to its absolute magnitude and extracts the hundreds, tens, and units (last digit) place values using integer division (`/`) and modulo (`%`) operations. It then prints the addition breakdown and final sum of these extracted digits.

## Features

- Continuous interactive loop processing (`while(1)`).
- Input validation catching non-numeric entries.
- Graceful exit mechanism when the user enters `0`.
- Automatic absolute value handling for negative integer inputs.
- Arithmetic digit extraction for 3-digit place values.
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
./sum_digits
```

## Usage Examples

**Positive Number Example:**

```text
=== Sum of Digits ===

Enter your number (0 to exit): 345

[SUCCESS] 3 + 4 + 5 = 12
Enter your number (0 to exit): 0

[INFO] Goodbye!
```

**Negative Number Example:**

```text
=== Sum of Digits ===

Enter your number (0 to exit): -123

[SUCCESS] 1 + 2 + 3 = 6
Enter your number (0 to exit): 0

[INFO] Goodbye!
```

**Invalid Input Error Example:**

```text
=== Sum of Digits ===

Enter your number (0 to exit): abc
[ERROR] Invalid input.
```