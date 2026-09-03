# Triangle Building

A simple C program demonstrating standard console input handling, non-negativity validation, overflow-safe integer casting, and application of the Triangle Inequality Theorem to determine if three side lengths can form a valid triangle.

## Description

This program prompts the user to enter three integer values representing side lengths (`height`, `width`, and `length`) from standard input (`stdin`). It validates each input to ensure numeric data is entered and confirms that all three values are strictly positive (`> 0`). It then casts side lengths to `long long` to prevent potential integer overflow and verifies the Triangle Inequality Theorem (`a + b > c`, `a + c > b`, `b + c > a`). If valid, it outputs "SUCCESS"; otherwise, it outputs "UNSUCCESS".

## Features

- Interactive command-line prompts for three side lengths.
- Comprehensive input validation for numeric data types.
- Strict positive range checks (`height > 0`, `width > 0`, `length > 0`).
- Safe evaluation using `long long` type conversion to prevent integer overflow.
- Application of the Triangle Inequality Theorem.
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
./triangle_building
```

## Usage Examples

**Valid Triangle Example:**

```text
Triangle building

Enter height: 3
Enter width: 4
Enter length: 5

SUCCESS
```

**Invalid Triangle Example (Violates Inequality):**

```text
Triangle building

Enter height: 1
Enter width: 2
Enter length: 3

UNSUCCESS
```

**Non-Positive Side Error Example:**

```text
Triangle building

Enter height: 0
Error: Triangle sides must be positive.
```

**Invalid Input Example:**

```text
Triangle building

Enter height: abc
Error: Invalid height.
```