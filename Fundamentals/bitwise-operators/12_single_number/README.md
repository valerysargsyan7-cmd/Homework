# Single Number Identifier

A C program demonstrating continuous input loop processing, input validation, and bitwise XOR (`^`) operations to identify a single distinct integer among three inputs.

## Description

This program continuously prompts the user in a loop to enter three integer values from standard input (`stdin`). It validates each input for numeric correctness. It checks if exactly two of the three numbers are equal while the third is distinct. Once a valid triplet meeting this condition is provided, it uses the bitwise XOR operation (`first_number ^ second_number ^ third_number`) to instantly isolate and display the unique "single" number, then terminates. If the input triplet does not contain exactly one distinct number paired with two matching numbers (e.g., all three numbers are equal or all three are unique), it prompts the user to try again.

## Features

- Interactive command-line prompts within an iterative `while` loop.
- Input validation catching non-numeric inputs and terminating on error.
- Bitwise XOR cancellation property (`A ^ A ^ B = B`) to extract the unique element.
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
./single_number
```

## Usage Examples

**Successful Single Number Identification Example:**

```text
Single number

Enter your first number: 42
Enter your second number: 99
Enter your third number: 42

Single number is: 99
```

**Retry Example (All Numbers Equal or Distinct):**

```text
Single number

Enter your first number: 5
Enter your second number: 5
Enter your third number: 5

Wrong, please try again!

Single number

Enter your first number: 10
Enter your second number: 20
Enter your third number: 10

Single number is: 20
```

**Invalid Input Type Example:**

```text
Single number

Enter your first number: abc
Error: Invalid input. Please enter an integer.
```