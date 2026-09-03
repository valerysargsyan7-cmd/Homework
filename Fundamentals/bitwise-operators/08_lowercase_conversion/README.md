# Lowercase or Uppercase (Bitwise Case Converter)

A simple C program demonstrating character input validation, ASCII range checking, and bitwise OR (`|`) operations to convert uppercase English letters to lowercase.

## Description

This program prompts the user to enter an English letter from standard input (`stdin`). It validates that a character was successfully scanned and verifies whether the input is an English letter (`A-Z` or `a-z`). If an uppercase letter (`A-Z`) is entered, it converts the character to lowercase by performing a bitwise OR operation with 32 (`user_letter | 32`). The program then outputs the resulting lowercase character.

## Features

- Interactive command-line prompt for character entry.
- Input validation ensuring character scanning and English alphabet range verification (`a-z`, `A-Z`).
- Case conversion to lowercase via bitwise OR (`| 32`).
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
./lowercase_uppercase
```

## Usage Examples

**Uppercase Letter Conversion Example:**

```text
Lowercase or uppercase

Enter your letter: G

LOWERCASE: g
```

**Lowercase Letter Passthrough Example:**

```text
Lowercase or uppercase

Enter your letter: m

LOWERCASE: m
```

**Non-English Character Error Example:**

```text
Lowercase or uppercase

Enter your letter: 9
Error: Please enter an English letter.
```