# Vowel Letter Counting
A C program demonstrating pointer-based string traversal and character comparison to count vowels in a string, case-insensitively.
## Description
This program prompts the user to enter a string (up to 199 characters) via standard input (`stdin`). It traverses the string using a pointer, checking each character against both the lowercase (`a`, `e`, `i`, `o`, `u`) and uppercase (`A`, `E`, `I`, `O`, `U`) vowels, and counts how many matches are found. The vowel count is then printed.
## Features
- Bounded string input (`%199s`) to prevent buffer overflow.
- Pointer-based string traversal (no index variables).
- Case-insensitive vowel counting (both lowercase and uppercase vowels matched).
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
./vowel_counting
```
## Usage Examples
**Vowel Counting Example:**
```text


Vowel Letter Counting


Enter your string with vowels: EDUCATION

Vowels: 5
```
**Failed Input Error Example:**
```text


Vowel Letter Counting


Enter your string with vowels: [ERROR] Failed to read string!
```