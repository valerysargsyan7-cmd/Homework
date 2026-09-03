# Scholarship Eligibility Checker

A simple C program demonstrating standard input processing, input validation, range checks, and conditional logic to evaluate scholarship qualification based on GPA and age.

## Description

This program prompts the user to enter their GPA (0–100 scale) as a floating-point number and their age as an integer from standard input (`stdin`). It validates both inputs for correct data types and enforces logical bounds (GPA between `0.0` and `100.0`, age non-negative). If the GPA is strictly greater than 90.0 and the age is strictly under 20, the program outputs "You get a scholarship"; otherwise, it outputs "You don't get a scholarship".

## Features

- Interactive command-line prompts for GPA and age.
- Comprehensive input validation to catch non-numeric entries.
- Boundary checks ensuring GPA is between 0 and 100, and age is non-negative.
- Multi-condition evaluation (`gpa > 90.0f && age < 20`).
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
./scholarship
```

## Usage Examples

**Eligible Student Example:**

```text
Scholarship

Enter your GPA: 92.5
Enter your age: 19

You get a scholarship
```

**Ineligible Student Example:**

```text
Scholarship

Enter your GPA: 95.0
Enter your age: 21

You don't get a scholarship
```

**Invalid GPA Out of Bounds Example:**

```text
Scholarship

Enter your GPA: 105.0
Error: GPA must be between 0 and 100.
```

**Invalid Input Type Example:**

```text
Scholarship

Enter your GPA: ninety
Error: Invalid GPA.
```