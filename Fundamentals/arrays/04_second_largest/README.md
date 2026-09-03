# Second Largest Element

A C program demonstrating array traversal, input validation, iterative maximum tracking, and finding the distinct second-largest element in an array.

## Description

This program prompts the user to enter 10 integer values sequentially via standard input (`stdin`). It stores each value in an array (`numbers[10]`) with input validation. After collection, it initializes tracking variables for the largest and second-largest elements, iterates through the remainder of the array to update them dynamically, checks that a distinct second-largest element exists, and prints the final result.

## Features

- Array storage for 10 sequential integer inputs.
- Interactive per-element console input prompts and validation.
- Iterative tracking algorithm for maximum and second-maximum values.
- Edge case handling for arrays lacking a distinct second-largest value.
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
./second_largest
```

## Usage Examples

**Successful Execution Example:**

```text
=== Second Largest Element ===

Enter element 1: 10
Enter element 2: 20
Enter element 3: 15
Enter element 4: 5
Enter element 5: 30
Enter element 6: 25
Enter element 7: 8
Enter element 8: 12
Enter element 9: 18
Enter element 10: 22

[SUCCESS] Second largest number: 25
```

**Invalid Input Error Example:**

```text
=== Second Largest Element ===

Enter element 1: abc
[ERROR] Invalid number.
```