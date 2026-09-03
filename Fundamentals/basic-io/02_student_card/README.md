# Student Card

A simple C program demonstrating standard console input/output handling, floating-point input processing, and validation for student profile data.

## Description

This program prompts the user to enter their age as an integer and their average academic mark as a floating-point number from standard input (`stdin`). It validates both inputs to ensure correct data types and verifies that neither the age nor the average score is negative before printing the student summary.

## Features

- Interactive command-line prompt for student age and score.
- Input validation to catch non-numeric input for both entries.
- Logical checks ensuring non-negative values (`age >= 0` and `score >= 0.0`).
- Formatted floating-point output displayed to two decimal places.
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
./student_card
```

## Usage Examples

**Valid Input Example:**

```text
Student card

Enter your age: 20
Enter your average mark: 87.5

Age: 20, Score: 87.50
```

**Negative Age Error Example:**

```text
Student card

Enter your age: -5
Error: Age cannot be negative.
```

**Negative Score Error Example:**

```text
Student card

Enter your age: 21
Enter your average mark: -1.5
Error: Score cannot be negative.
```

**Invalid Input Example:**

```text
Student card

Enter your age: twenty
Error: Invalid input. Please enter a valid integer.
```