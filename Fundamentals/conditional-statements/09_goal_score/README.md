# Goal Calculating

A simple C program demonstrating standard console input handling, input validation, and range checks to evaluate whether a shot lands within a target goal area.

## Description

This program prompts the user to enter a hit location number from standard input (`stdin`). It validates the input to ensure a valid integer is provided and checks if the hit location falls within the range of 1 to 10 (inclusive). If the input is within range, it outputs "GOAL"; otherwise, it outputs "OUT".

## Features

- Interactive command-line prompt for target location entry.
- Input validation to catch non-integer entries.
- Inclusive range checking (`1 <= goal_num <= 10`).
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
./goal_calculating
```

## Usage Examples

**Goal Example:**

```text
Goal calculating

Enter your hit place: 5

GOAL
```

**Out Example:**

```text
Goal calculating

Enter your hit place: 12

OUT
```

**Invalid Input Example:**

```text
Goal calculating

Enter your hit place: abc
Error: Invalid input. Please enter a valid integer.
```