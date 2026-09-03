# Array Copy

A C program demonstrating character array storage, interactive console input processing with whitespace skipping, iterative copying, and indexed output formatting.

## Description

This program prompts the user to input 5 characters sequentially via standard input (`stdin`). It stores each entered character into a source array (`source_array[5]`) while validating input success. It then copies each element from the source array into a destination array (`destination_array[5]`) via an iterative loop and outputs the copied values.

## Features

- Character array creation and fixed-size iteration using `for` loops.
- Bounded input reading with whitespace skipping (`" %c"` specifier) in `scanf`.
- Element-by-element array copying.
- Error handling for invalid or failed character reads.
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
./array_copy
```

## Usage Examples

**Character Array Copy Example:**

```text
=== Array Copy ===

Enter value 0: a
Enter value 1: b
Enter value 2: c
Enter value 3: d
Enter value 4: e

Copied values:

[INFO] Value 0: a

[INFO] Value 1: b

[INFO] Value 2: c

[INFO] Value 3: d

[INFO] Value 4: e
```

**Failed Input Example:**

```text
=== Array Copy ===

Enter value 0: 
[ERROR] Failed to read character.
```