# Lowercase to Uppercase

A C program demonstrating character case conversion using ASCII arithmetic, bounded string input handling via `scanf`, and iterative string traversal.

## Description

This program prompts the user to input a single lowercase word (up to 19 characters) via standard input (`stdin`). It uses `%19s` to safely bound the input and prevent buffer overflow vulnerabilities. It then iterates through the character array until the null-terminator (`'\0'`) is reached, checking if each character falls within the lowercase ASCII range (`'a'` to `'z'`). If it does, it subtracts 32 from its ASCII value to convert it to its uppercase equivalent before printing the modified string.

## Features

- Bounded string input using `%19s` format specifiers for buffer protection.
- Iterative string traversal checking for the null character (`'\0'`).
- Manual ASCII case conversion using mathematical subtraction (`-= 32`).
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
./lowercase_to_uppercase
```

## Usage Examples

**Case Conversion Example:**

```text
=== Lowercase to Uppercase ===

Enter your word in lowercase: hello

[SUCCESS] Uppercase word: HELLO
```

**Failed Input Handling Example:**

```text
=== Lowercase to Uppercase ===

Enter your word in lowercase: 
[ERROR] Failed to read the word.
```