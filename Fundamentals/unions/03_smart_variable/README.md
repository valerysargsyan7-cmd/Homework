# Smart Variable Array

A C program demonstrating tagged union patterns, array storage, interactive standard console input processing, enumerations (`enum`), unions (`union`), structures (`struct`), and cumulative sum calculation across heterogeneous numeric types.

## Description

This program creates an array of 5 `struct Variable` instances, implementing a tagged union pattern using `enum DataType` (`INT` or `FLOAT`) and `union IntOrFloat`. It loops through each element, prompting the user to specify whether the variable should store an integer or a floating-point number. Based on the selected type, it reads the input value, stores it in the union field, and accumulates all entries into a total sum displayed with two decimal places.

## Features

- Tagged union implementation using `enum DataType` and `union IntOrFloat` encapsulated in `struct Variable`.
- Array of 5 tagged union structures processed iteratively using a `for` loop.
- Interactive CLI prompt for selecting numeric type (`0` for `INT`, `1` for `FLOAT`) per element.
- Input validation for menu selection, integer values, and floating-point entries.
- Accumulation of heterogeneous inputs into a unified floating-point sum.
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
./smart_variable
```

## Usage Examples

**Heterogeneous Array Input Example:**

```text
=== Smart Variable ===

Variable 1/5
  0 - INT
  1 - FLOAT
Enter type: 0
Enter INT value: 10
Variable 2/5
  0 - INT
  1 - FLOAT
Enter type: 1
Enter FLOAT value: 5.5
Variable 3/5
  0 - INT
  1 - FLOAT
Enter type: 0
Enter INT value: 20
Variable 4/5
  0 - INT
  1 - FLOAT
Enter type: 1
Enter FLOAT value: 2.25
Variable 5/5
  0 - INT
  1 - FLOAT
Enter type: 0
Enter INT value: 3

[SUCCESS] Total: 40.75
```

**Invalid Type Choice Error Example:**

```text
=== Smart Variable ===

Variable 1/5
  0 - INT
  1 - FLOAT
Enter type: 2
[ERROR] Type must be 0 or 1.
```

**Invalid Numeric Value Error Example:**

```text
=== Smart Variable ===

Variable 1/5
  0 - INT
  1 - FLOAT
Enter type: 0
Enter INT value: abc
[ERROR] Invalid integer value.
```