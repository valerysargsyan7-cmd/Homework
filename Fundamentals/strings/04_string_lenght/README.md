# String Length Calculator

A C program demonstrating manual string length calculation, bounded input reading via `scanf`, null-terminated array traversal, and iterative counting.

## Description

This program prompts the user to enter a single word or string (up to 19 characters) via standard input (`stdin`). It restricts the input using `%19s` to protect against buffer overflows. Instead of using standard library functions like `strlen`, it manually loops through the character array until the null-terminator (`'\0'`) is reached, incrementing a counter variable to determine the string length before displaying the final count.

## Features

- Bounded string input using `%19s` specifiers to prevent buffer overflow.
- Manual string length calculation via a `for` loop traversal checking for the null character (`'\0'`).
- Input validation ensuring successful string acquisition.
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
./string_length
```

## Usage Examples

**Successful Length Calculation Example:**

```text
=== String Length ===

Enter your word: Developer

[SUCCESS] String length: 9
```

**Failed Input Handling Example:**

```text
=== String Length ===

Enter your word: 
[ERROR] Failed to read the string.
```