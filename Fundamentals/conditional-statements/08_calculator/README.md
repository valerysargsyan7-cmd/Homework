# Simple Calculator

A simple C program demonstrating standard console input/output handling, character parsing, and conditional branch evaluation for basic arithmetic operations.

## Description

This program prompts the user to enter two integers and an arithmetic operator (`+`, `-`, `*`, `/`) from standard input (`stdin`). It validates each input, checks for division-by-zero errors when dividing, and evaluates the requested arithmetic operation.

## Features

- Interactive command-line interface for simple arithmetic.
- Input validation for numeric inputs and operators.
- Division-by-zero protection.
- Support for basic operators: addition (`+`), subtraction (`-`), multiplication (`*`), and integer division (`/`).
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
./calculator
```

## Usage Examples

**Addition Example:**

```text
Calculator

Enter first number: 12
Enter operator (+ - * /): +
Enter second number: 8

Result: 20
```

**Division Example:**

```text
Calculator

Enter first number: 20
Enter operator (+ - * /): /
Enter second number: 4

Result: 5
```

**Division by Zero Error Example:**

```text
Calculator

Enter first number: 10
Enter operator (+ - * /): /
Enter second number: 0
Error: Division by zero is not allowed.
```

**Invalid Operator Example:**

```text
Calculator

Enter first number: 10
Enter operator (+ - * /): %
Enter second number: 5
Error: Invalid operator. Use +, -, * or /.