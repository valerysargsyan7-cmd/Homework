# Scholarship by Grade

A simple C program demonstrating custom enumeration (`enum`), integer cast validation, range checking, and `switch` statement control flow to evaluate scholarship eligibility based on academic grades.

## Description

This program defines a custom `enum Grade` mapping academic ratings from `POOR` (2) to `EXCELLENT` (5). It prompts the user for an integer grade via standard input (`stdin`), validates that the entry lies strictly within the range of 2 to 5, and explicitly casts the value to the `enum Grade` type. A `switch` block evaluates the enumeration value, awarding a scholarship for `GOOD` or `EXCELLENT` scores, or denying it for `POOR` or `SATISFACTORY` ratings.

## Features

- Custom C enumeration type definition (`enum Grade`).
- Interactive command-line prompt for academic grade inputs.
- Input validation catching non-numeric entries and out-of-bounds values (`2 <= grade <= 5`).
- Explicit integer-to-enumeration type conversion (`(enum Grade)grade_input`).
- Switch-case logic for conditional program branching.
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

**Scholarship Awarded Example:**

```text
=== Scholarship by Grade ===

Enter your grade (POOR-2, SATISFACTORY-3, GOOD-4, EXCELLENT-5): 5

[SUCCESS] Scholarship awarded.
```

**No Scholarship Example:**

```text
=== Scholarship by Grade ===

Enter your grade (POOR-2, SATISFACTORY-3, GOOD-4, EXCELLENT-5): 3

[INFO] No scholarship.
```

**Out of Range Error Example:**

```text
=== Scholarship by Grade ===

Enter your grade (POOR-2, SATISFACTORY-3, GOOD-4, EXCELLENT-5): 1
[ERROR] Grade must be between 2 and 5.
```

**Invalid Input Type Example:**

```text
=== Scholarship by Grade ===

Enter your grade (POOR-2, SATISFACTORY-3, GOOD-4, EXCELLENT-5): abc
[ERROR] Invalid grade.
```