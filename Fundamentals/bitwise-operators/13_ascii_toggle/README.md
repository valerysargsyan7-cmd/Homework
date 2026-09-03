# ASCII Toggle (Letter Case Inverter)

A simple C program demonstrating character input reading, alphabetic character validation, and bitwise XOR (`^`) operations to toggle the case of ASCII English letters.

## Description

This program prompts the user to enter a single character from standard input (`stdin`). It validates that the input is a valid ASCII English letter (`A`–`Z` or `a`–`z`). It then uses the bitwise XOR operation with 32 (`symbol ^ 32`), which toggles the 6th bit (0x20) in ASCII representation, effectively converting uppercase letters to lowercase and lowercase letters to uppercase.

## Features

- Interactive command-line prompt for character input.
- Leading whitespace handling in `scanf(" %c", &symbol)`.
- Input validation restricting input to uppercase and lowercase English alphabetic characters.
- Bitwise XOR bit-flip operation (`^ 32`) for ASCII case toggling.
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
./ascii_toggle
```

## Usage Examples

**Uppercase to Lowercase Example:**

```text
ASCII Toggle

Enter your letter: A

Toggled letter: a
```

**Lowercase to Uppercase Example:**

```text
ASCII Toggle

Enter your letter: z

Toggled letter: Z
```

**Non-English Letter Error Example:**

```text
ASCII Toggle

Enter your letter: 5
Error: Please enter an English letter.
```