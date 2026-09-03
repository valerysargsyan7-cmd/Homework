# Rectangle Perimeter Calculator

A simple C program demonstrating custom structure definition (`struct`), standard input processing, non-positivity validation, square identification, and perimeter calculation.

## Description

This program defines a custom `struct Rectangle` to encapsulate integer `width` and `height` properties. It prompts the user for both dimensions via standard input (`stdin`), validates that valid integer values were provided, and ensures both dimensions are strictly positive. If the width equals the height, it identifies the shape as a square. Otherwise, it calculates and displays the rectangle's perimeter using the formula $2 \times (\text{width} + \text{height})$.

## Features

- Custom C structure encapsulation (`struct Rectangle`).
- Interactive command-line prompts for width and height dimensions.
- Input validation catching non-numeric entries for each prompt.
- Non-positivity check ensuring both width and height are strictly greater than zero.
- Special case identification for square geometry.
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
./rectangle_perimeter
```

## Usage Examples

**Standard Rectangle Example:**

```text
=== Rectangle Perimeter ===

Enter width: 5
Enter height: 10

[SUCCESS] Perimeter is: 30
```

**Square Identification Example:**

```text
=== Rectangle Perimeter ===

Enter width: 7
Enter height: 7

[INFO] This rectangle is a square.
```

**Non-Positive Input Error Example:**

```text
=== Rectangle Perimeter ===

Enter width: 0
Enter height: 5
[ERROR] Width and height must be positive.
```

**Invalid Input Type Example:**

```text
=== Rectangle Perimeter ===

Enter width: abc
[ERROR] Invalid width.
```