# Letter Checking (Vowel Checker)

A simple C program demonstrating character input handling, input validation, and conditional branch evaluation to check whether an entered character is a vowel.

## Description

This program prompts the user to enter a character from standard input (`stdin`). It validates that a character was successfully read and evaluates whether it matches any lowercase or uppercase English vowel (`a`, `e`, `i`, `o`, `u`, `A`, `E`, `I`, `O`, `U`). If it matches, the program outputs "Vowel"; otherwise, it outputs "Non-vowel".

## Features

- Interactive command-line prompt for character entry.
- Input validation verifying character scanning.
- Case-insensitive vowel detection (`a`, `e`, `i`, `o`, `u`, `A`, `E`, `I`, `O`, `U`).
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
./letter_checking
```

## Usage Examples

**Lowercase Vowel Example:**

```text
Letter checking

Enter letter: e

Vowel
```

**Uppercase Vowel Example:**

```text
Letter checking

Enter letter: A

Vowel
```

**Consonant / Non-Vowel Example:**

```text
Letter checking

Enter letter: z

Non-vowel
```