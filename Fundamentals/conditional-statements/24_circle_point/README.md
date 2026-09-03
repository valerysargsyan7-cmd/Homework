# Circle and Point (Inside/Outside Checker)

A simple C program demonstrating standard floating-point input processing, non-negativity validation, and Euclidean distance comparison to evaluate whether a point $(x, y)$ lies inside or on the boundary of a circle centered at the origin $(0, 0)$ with a given radius $r$.

## Description

This program prompts the user to enter floating-point numbers for the X coordinate, Y coordinate, and radius of a circle centered at the origin $(0, 0)$ from standard input (`stdin`). It validates each input for numeric correctness and checks that the radius is non-negative. Using the algebraic equation of a circle ($x^2 + y^2 \le r^2$), it determines if the point resides inside or on the perimeter of the circle. If true, it outputs "True"; otherwise, it outputs "False".

## Features

- Interactive command-line prompts for X coordinate, Y coordinate, and radius.
- Input validation catching non-numeric entries for floating-point values.
- Non-negativity check for the circle's radius (`radius >= 0.0f`).
- Geometric point-in-circle validation using $(x^2 + y^2 \le r^2)$.
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
./circle_point
```

## Usage Examples

**Inside Circle Example:**

```text
Circle and point

Enter X coordinate: 2.0
Enter Y coordinate: 3.0
Enter radius: 5.0

True
```

**On Circle Boundary Example:**

```text
Circle and point

Enter X coordinate: 3.0
Enter Y coordinate: 4.0
Enter radius: 5.0

True
```

**Outside Circle Example:**

```text
Circle and point

Enter X coordinate: 6.0
Enter Y coordinate: 1.0
Enter radius: 5.0

False
```

**Negative Radius Error Example:**

```text
Circle and point

Enter X coordinate: 1.0
Enter Y coordinate: 1.0
Enter radius: -2.0
Error: Radius cannot be negative.
```

**Invalid Input Type Example:**

```text
Circle and point

Enter X coordinate: abc
Error: Invalid X coordinate.
```