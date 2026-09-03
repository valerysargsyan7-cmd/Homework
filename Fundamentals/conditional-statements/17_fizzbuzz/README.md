# FizzBuzz Single Number Evaluator

A simple C program demonstrating standard input processing, input validation, modulo arithmetic (`%`), and conditional branching to evaluate a single integer according to FizzBuzz rules.

## Description

This program prompts the user to enter an integer from standard input (`stdin`). It validates that a valid integer was supplied, then evaluates the number using modulo arithmetic:
- If divisible by both 3 and 5, it prints "FizzBuzz".
- If divisible only by 3, it prints "Fizz".
- If divisible only by 5, it prints "Buzz".
- If divisible by neither, it prints the original integer value.

## Features

- Interactive command-line prompt for integer input.
- Input validation catching non-numeric inputs.
- Modulo arithmetic evaluation (`% 3` and `% 5`).
- Conditional branching with prioritized combined condition check.
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
./fizzbuzz
```

## Usage Examples

**FizzBuzz Example (Divisible by 3 and 5):**

```text
FizzBuzz

Enter your FizzBuzz number: 15

FizzBuzz
```

**Fizz Example (Divisible by 3):**

```text
FizzBuzz

Enter your FizzBuzz number: 9

Fizz
```

**Buzz Example (Divisible by 5):**

```text
FizzBuzz

Enter your FizzBuzz number: 10

Buzz
```

**Passthrough Example (Divisible by neither):**

```text
FizzBuzz

Enter your FizzBuzz number: 7

7
```

**Invalid Input Example:**

```text
FizzBuzz

Enter your FizzBuzz number: abc
Error: Invalid input. Please enter an integer.
```