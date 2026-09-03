# 3D Point Coordinates

A simple C program demonstrating custom `typedef struct` definition, standard floating-point input processing, origin detection, and formatted coordinate output.

## Description

This program defines a custom type `Point3D` using a `typedef struct` to encapsulate 3D spatial coordinates (`x`, `y`, and `z` as floating-point numbers). It prompts the user for each coordinate from standard input (`stdin`) and validates the numeric input. It checks whether the point is located at the origin `(0.00, 0.00, 0.00)`. If at the origin, it outputs an informational message; otherwise, it prints the formatted coordinates with two decimal places precision.

## Features

- Custom C structure definition using `typedef struct Point3D`.
- Interactive command-line prompts for X, Y, and Z floating-point coordinates.
- Input validation catching non-numeric entries for each coordinate prompt.
- Special-case checking for the 3D space origin point (`0.0, 0.0, 0.0`).
- Precision-formatted floating-point output (`%.2f`).
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
./point_3d
```

## Usage Examples

**Standard 3D Point Example:**

```text
=== Point in 3D ===

Enter coordinate X: 1.5
Enter coordinate Y: -2.3
Enter coordinate Z: 4.0

[SUCCESS] Point: 1.50 : -2.30 : 4.00
```

**Origin Point Example:**

```text
=== Point in 3D ===

Enter coordinate X: 0
Enter coordinate Y: 0
Enter coordinate Z: 0

[INFO] Origin point.
```

**Invalid Input Type Example:**

```text
=== Point in 3D ===

Enter coordinate X: 1.0
Enter coordinate Y: abc
[ERROR] Invalid Y coordinate.
```