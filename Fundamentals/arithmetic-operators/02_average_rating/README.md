# Grade Average Calculator

A simple C program demonstrating standard input handling, input validation, and basic floating-point calculations for academic grade averages.

## Description

This program prompts the user to enter integer marks for four subjects: English, Math, Physics, and History from standard input (`stdin`). It validates each input to ensure valid numeric data is provided, calculates the arithmetic mean of the four grades, and prints the result formatted to two decimal places.

## Features

- Interactive command-line prompt for individual subject marks.
- Input validation for each entry to prevent invalid numerical input.
- Floating-point arithmetic calculation for precise average output.
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
./grade_average
```

## Usage Examples

**Valid Input Example:**

```text
Average rating

Enter your English mark: 85
Enter your Math mark: 90
Enter your Physics mark: 78
Enter your History mark: 92
Your average score is: 86.25
```

**Invalid Input Example:**

```text
Average rating

Enter your English mark: abc
Error: Invalid input. Please enter a valid integer.
```