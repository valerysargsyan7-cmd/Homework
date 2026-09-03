# Logic Gates: AND / OR

A simple C program demonstrating boolean input validation and evaluation of basic logical operations (AND and OR).

## Description

This program prompts the user to enter two bit values (`0` or `1`) from standard input (`stdin`). It validates each input to ensure numeric data is entered and checks that both inputs strictly equal `0` or `1`. Upon validation, it evaluates and displays the results of logical AND (`&&`) and logical OR (`||`) operations.

## Features

- Interactive command-line prompt for bit values.
- Strict input validation catching non-integer input and non-binary integers.
- Logical AND (`&&`) operation evaluation.
- Logical OR (`||`) operation evaluation.
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
./logic_gates
```

## Usage Examples

**Both Bits Set (1 AND 1):**

```text
Logic gates: AND / OR

Enter first bit value (0 or 1): 1
Enter second bit value (0 or 1): 1

Result of AND: 1

Result of OR: 1
```

**One Bit Set (1 OR 0):**

```text
Logic gates: AND / OR

Enter first bit value (0 or 1): 1
Enter second bit value (0 or 1): 0

Result of AND: 0

Result of OR: 1
```

**Out of Range Bit Value Error Example:**

```text
Logic gates: AND / OR

Enter first bit value (0 or 1): 5
Enter second bit value (0 or 1): 0
Error: Bit values must be 0 or 1.
```

**Invalid Input Example:**

```text
Logic gates: AND / OR

Enter first bit value (0 or 1): abc
Error: Invalid input. Please enter 0 or 1.
```