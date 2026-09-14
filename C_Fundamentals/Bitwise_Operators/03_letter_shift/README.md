# Letter Shift

A simple C program demonstrating character input validation, ASCII boundary checks, and basic character arithmetic.

## Description

This program prompts the user to enter an English alphabet letter (lowercase or uppercase) from standard input (`stdin`). It validates that the character provided is an English letter, ensures that the letter is not the first letter of the alphabet (`'a'` or `'A'`), and calculates and prints the preceding character in ASCII sequence.

## Features

- Interactive command-line prompt for character input.
- Input validation for character scanning.
- Boundary checks verifying that input is within `'a'-'z'` or `'A'-'Z'`.
- Protection against shifting prior to `'a'` or `'A'`.
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
./letter_shift
```

## Usage Examples

**Valid Lowercase Example:**

```text
Letter shift

Enter your letter: b

Previous letter: a
```

**Valid Uppercase Example:**

```text
Letter shift

Enter your letter: Z

Previous letter: Y
```

**First Letter Error Example:**

```text
Letter shift

Enter your letter: a
Error: Cannot shift before the first letter.
```

**Non-English Character Error Example:**

```text
Letter shift

Enter your letter: 5
Error: Please enter an English letter.
```