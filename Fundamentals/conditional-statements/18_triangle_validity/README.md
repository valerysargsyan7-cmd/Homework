# Triangle Checking (Validator & Classifier)

A simple C program demonstrating standard console input processing, input validation, non-positivity checks, triangle inequality verification, and geometric side-length classification.

## Description

This program prompts the user to enter three side lengths as integers from standard input (`stdin`). It validates each input for integer correctness and verifies that all side lengths are strictly positive. Next, it checks the Triangle Inequality Theorem to determine if the given side lengths can form a valid non-degenerate triangle. If valid, it outputs "SUCCESS" and further classifies the triangle as "EQUILATERAL", "ISOSCELES", or "SCALENE". Otherwise, it outputs "UNSUCCESS".

## Features

- Interactive command-line prompts for three integer side lengths.
- Input validation catching non-numeric entries.
- Positivity validation ensuring all side lengths are strictly greater than zero.
- Overflow-safe triangle inequality validation using `(long long)` casting.
- Geometric classification into Equilateral, Isosceles, or Scalene triangles.
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
./triangle_check
```

## Usage Examples

**Equilateral Triangle Example:**

```text
Triangle checking

Enter your first side: 5
Enter your second side: 5
Enter your third side: 5

SUCCESS

EQUILATERAL
```

**Isosceles Triangle Example:**

```text
Triangle checking

Enter your first side: 5
Enter your second side: 5
Enter your third side: 8

SUCCESS

ISOSCELES
```

**Scalene Triangle Example:**

```text
Triangle checking

Enter your first side: 3
Enter your second side: 4
Enter your third side: 5

SUCCESS

SCALENE
```

**Invalid Triangle Inequality Example:**

```text
Triangle checking

Enter your first side: 1
Enter your second side: 2
Enter your third side: 3

UNSUCCESS
```

**Non-Positive Input Error Example:**

```text
Triangle checking

Enter your first side: 0
Error: Triangle sides must be positive.
```