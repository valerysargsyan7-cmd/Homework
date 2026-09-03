# Face Control Eligibility Check

A simple C program demonstrating standard console input processing, input validation, non-negativity checks, and logical threshold evaluation for age and height requirements.

## Description

This program prompts the user to enter their age as an integer and their height as a floating-point number from standard input (`stdin`). It validates both inputs to ensure correct data types are provided and checks that neither value is negative. It then evaluates whether the age is strictly greater than 18 and the height is strictly greater than 1.60, printing `1` (true) if both criteria are satisfied or `0` (false) otherwise.

## Features

- Interactive command-line prompts for age and height.
- Input validation catching non-numeric input types.
- Non-negativity check (`person_age >= 0` and `person_height >= 0.0f`).
- Evaluation of logical conjunction (`person_age > 18 && person_height > 1.60f`).
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
./face_control
```

## Usage Examples

**Eligible Criteria Met (Outputs 1):**

```text
Face control

Enter your age: 20
Enter your height: 1.75

1
```

**Ineligible Criteria Not Met (Outputs 0):**

```text
Face control

Enter your age: 17
Enter your height: 1.75

0
```

**Negative Input Error Example:**

```text
Face control

Enter your age: -5
Enter your height: 1.70
Error: Age and height cannot be negative.
```

**Invalid Input Type Example:**

```text
Face control

Enter your age: twenty
Error: Invalid age.
```