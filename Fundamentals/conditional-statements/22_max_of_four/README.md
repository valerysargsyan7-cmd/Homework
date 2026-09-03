# Maximum of 4

A simple C program demonstrating standard input processing, input validation, and linear scanning logic to find the maximum among four integer values.

## Description

This program prompts the user to enter four integers from standard input (`stdin`). It validates each input to ensure valid numeric data is provided. It initializes the maximum value to the first integer and sequentially compares it against the second, third, and fourth integers, updating the maximum whenever a larger value is encountered before printing the final result.

## Features

- Interactive command-line prompts for four integer inputs.
- Input validation catching non-numeric entries for each prompt.
- Linear comparison algorithm to determine the largest value.
- Support for positive, negative, and zero values.
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
./max_of_four
```

## Usage Examples

**Positive Integers Example:**

```text
Maximum of 4

Enter first number: 12
Enter second number: 45
Enter third number: 7
Enter fourth number: 23

Maximum: 45
```

**Negative Integers Example:**

```text
Maximum of 4

Enter first number: -10
Enter second number: -3
Enter third number: -50
Enter fourth number: -8

Maximum: -3
```

**Invalid Input Example:**

```text
Maximum of 4

Enter first number: 10
Enter second number: abc
Error: Invalid input.
```