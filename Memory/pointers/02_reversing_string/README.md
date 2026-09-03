# Reversing String By Pointer
A C program demonstrating in-place string reversal using two converging pointers, without index variables.
## Description
This program prompts the user to enter a string (up to 199 characters) via standard input (`stdin`). It reverses the string in place using two pointers — one starting at the first character and one advanced to the last character before the null terminator — swapping the characters they point to and moving the pointers toward each other until they meet or cross. The reversed string is then printed.
## Features
- Bounded string input (`%199s`) to prevent buffer overflow.
- Pointer-based traversal to locate the end of the string (no `strlen`).
- Two-pointer, in-place swap technique for reversal, with no index variables.
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
./reversing_string
```
## Usage Examples
**Reversing Example:**
```text


Reversing String By Pointer


Enter your string: hello

Reversed: olleh
```
**Failed Input Error Example:**
```text


Reversing String By Pointer


Enter your string: [ERROR] Failed to read string!
```