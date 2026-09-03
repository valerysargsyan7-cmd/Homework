# Calculating Coordinates (Quadrant Checker)

A simple C program demonstrating standard floating-point input handling, input validation, and conditional branch evaluation to determine the 2D Cartesian quadrant or axis location of a point.

## Description

This program prompts the user to enter 2D Cartesian coordinates ($X$ and $Y$) as floating-point values from standard input (`stdin`). It validates both inputs to ensure numeric values are provided and evaluates the coordinates to identify whether the point lies in Quadrant I, II, III, or IV, at the origin, or on the X or Y axis.

## Features

- Interactive command-line prompt for $X$ and $Y$ floating-point coordinates.
- Comprehensive input validation to catch non-numeric entries.
- Multi-branch conditional logic mapping points to standard Cartesian quadrants ($I$, $II$, $III$, $IV$), origin $(0,0)$, or axis lines.
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
./coord_checker
```

## Usage Examples

**Quadrant I Example:**

```text
Calculating coordinates

Enter X: 3.5
Enter Y: 4.2

You are in I quadrant
```

**Quadrant III Example:**

```text
Calculating coordinates

Enter X: -2.0
Enter Y: -5.1

You are in III quadrant
```

**Origin Example:**

```text
Calculating coordinates

Enter X: 0
Enter Y: 0

You are at the origin
```

**Axis Location Example:**

```text
Calculating coordinates

Enter X: 0
Enter Y: 7.5

You are on the Y axis
```

**Invalid Input Example:**

```text
Calculating coordinates

Enter X: abc
Error: Invalid X coordinate.
```