# Vowel Count

A C program demonstrating character array analysis, string traversal until null termination, conditional vowel matching, and safe console input handling.

## Description

This program prompts the user to input a single word (up to 19 characters) via standard input (`stdin`). It restricts the input using `%19s` to protect against buffer overflows. It then iterates through the character array, checking each character against lowercase vowels (`a`, `e`, `i`, `o`, `u`), increments a counter for every match found, and prints the total vowel count.

## Features

- Bounded string reading using `%19s` format specifiers to prevent buffer overflow vulnerabilities.
- Iterative array traversal checking for the null terminator (`'\0'`).
- Conditional checks matching lowercase vowels.
- Error handling for failed input reads.
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
./vowel_count
```

## Usage Examples

**Vowel Counting Example:**

```text
=== Vowel Count ===

Enter your word: computer

[SUCCESS] Number of vowels: 3
```

**Failed Input Handling Example:**

```text
=== Vowel Count ===

Enter your word: 
[ERROR] Failed to read the word.
```