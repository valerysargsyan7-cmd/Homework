# Three / Four / None (Divisibility Evaluator)

A simple C program demonstrating standard console input processing, input validation, modulo arithmetic (`%`), and conditional branching to evaluate an integer's divisibility by 3 and 4.

## Description

This program prompts the user to enter an integer from standard input (`stdin`). It validates that a valid integer was entered and checks its divisibility:
- If divisible by both 3 and 4, it prints "Perfect".
- If divisible only by 3, it prints "Three".
- If divisible only by 4, it prints "Four".
- If divisible by neither, it outputs the original integer.

## Features

- Interactive command-line prompt for integer input.
- Input validation catching non-numeric inputs.
- Modulo arithmetic evaluation (`% 3` and `% 4`).
- Priority-ordered conditional branching.
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
./three_four_none
```

## Usage Examples

**Both 3 and 4 Example (Perfect):**

```text
Three / four / none

Enter your number: 12

Perfect
```

**Divisible by 3 Example:**

```text
Three / four / none

Enter your number: 9

Three
```

**Divisible by 4 Example:**

```text
Three / four / none

Enter your number: 16

Four
```

**Neither Example:**

```text
Three / four / none

Enter your number: 7

7
```

**Invalid Input Example:**

```text
Three / four / none

Enter your number: abc
Error: Invalid input. Please enter an integer.
```