# Combined Type (Tagged Union)

A simple C program demonstrating tagged union patterns, standard console input validation, enumerations (`enum`), unions (`union`), structures (`struct`), and conditional execution flow.

## Description

This program implements a tagged union pattern using a custom `struct Data` containing an explicit type tag (`enum TypeChoice`) alongside a `union Value`. It prompts the user to select a data type (`0` for integer or `1` for character) via standard input (`stdin`). The input is validated for correctness and range. Based on the selected data type, the program assigns either an integer value (`100`) or a character value (`'A'`) to the union field and displays the stored result.

## Features

- Tagged union implementation encapsulating `enum TypeChoice` and `union Value` inside `struct Data`.
- Interactive command-line prompt for data type selection.
- Strict input validation catching non-numeric entries and out-of-range choices (`0` or `1`).
- Explicit enum casting and type-safe value assignment.
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
./combined_type
```

## Usage Examples

**Integer Type Choice Example:**

```text
=== Combined Type ===

Enter your data type (INT-0, CHAR-1): 0

[SUCCESS] Your data is: 100
```

**Character Type Choice Example:**

```text
=== Combined Type ===

Enter your data type (INT-0, CHAR-1): 1

[SUCCESS] Your data is: A
```

**Out of Range Error Example:**

```text
=== Combined Type ===

Enter your data type (INT-0, CHAR-1): 2
[ERROR] Data type must be 0 or 1.
```

**Invalid Input Type Example:**

```text
=== Combined Type ===

Enter your data type (INT-0, CHAR-1): abc
[ERROR] Invalid data type.
```