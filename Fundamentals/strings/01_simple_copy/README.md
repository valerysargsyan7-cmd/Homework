# Simple Copy

A C program demonstrating standard string manipulation using standard library functions (`strcpy` and `strlen`), bounded input processing with `scanf`, character array buffer handling, and output formatting.

## Description

This program prompts the user to input a single word (up to 19 characters) via standard input (`stdin`). It reads the input using `%19s` to prevent buffer overflows, copies the string into a secondary destination buffer using `strcpy`, calculates its length using `strlen`, and prints both the copied string and its character count.

## Features

- Bounded string reading via `%19s` specifier in `scanf` to prevent buffer overflow vulnerabilities.
- Safe buffer copying using C standard library `strcpy`.
- String length calculation utilizing `strlen` and `size_t` precision.
- Input validation verifying successful string acquisition.
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
./simple_copy
```

## Usage Examples

**Successful String Copy Example:**

```text
=== Simple Copy ===

Enter your word: Hello

[SUCCESS] Your string: 'Hello'
[INFO] String length: 5
```

**Long Word Example:**

```text
=== Simple Copy ===

Enter your word: Programming

[SUCCESS] Your string: 'Programming'
[INFO] String length: 11
```