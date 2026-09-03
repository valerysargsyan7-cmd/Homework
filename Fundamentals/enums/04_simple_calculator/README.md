# Simple Calculator

A C program demonstrating custom enumeration (`enum`), standard console input handling, division-by-zero validation, and `switch` statement control flow to perform basic arithmetic operations.

## Description

This program defines a custom `enum Operation` representing four basic arithmetic operations: `ADD` (0), `SUBTRACT` (1), `MULTIPLY` (2), and `DIVIDE` (3). It prompts the user for a first integer, an operation selection, and a second integer via standard input (`stdin`). The program validates all numeric inputs, verifies that the operation choice is within bounds, prevents division by zero, and computes the result using a `switch` statement.

## Features

- Custom C enumeration type definition (`enum Operation`).
- Interactive command-line menu for selecting operations.
- Full input validation for all operands and menu selections.
- Explicit division-by-zero protection.
- `switch`-based execution logic for arithmetic branching.
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
./simple_calculator
```

## Usage Examples

**Addition Example:**

```text
=== Simple Calculator ===

Enter first number: 10
Enter operation:
  0 - Add
  1 - Subtract
  2 - Multiply
  3 - Divide

Choice: 0
Enter second number: 5

[SUCCESS] Result: 15
```

**Division Example:**

```text
=== Simple Calculator ===

Enter first number: 20
Enter operation:
  0 - Add
  1 - Subtract
  2 - Multiply
  3 - Divide

Choice: 3
Enter second number: 4

[SUCCESS] Result: 5
```

**Division by Zero Error Example:**

```text
=== Simple Calculator ===

Enter first number: 10
Enter operation:
  0 - Add
  1 - Subtract
  2 - Multiply
  3 - Divide

Choice: 3
Enter second number: 0
[ERROR] Division by zero is not allowed.
```

**Invalid Operation Choice Example:**

```text
=== Simple Calculator ===

Enter first number: 5
Enter operation:
  0 - Add
  1 - Subtract
  2 - Multiply
  3 - Divide

Choice: 4
[ERROR] Invalid operation.
```