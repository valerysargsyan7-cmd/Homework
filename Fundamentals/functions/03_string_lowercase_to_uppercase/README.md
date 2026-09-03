# String Lowercase to Uppercase Changing
A C program demonstrating character classification, bounded string input, and in-place string modification via pointer traversal to convert lowercase letters to uppercase.
## Description
This program prompts the user to enter a string (up to 19 characters) via standard input (`stdin`). It traverses the string using a pointer, checking each character with an `isAlpha` helper function, and converts any lowercase letter to its uppercase equivalent in place. Non-alphabetic and already-uppercase characters are left unchanged. The modified string is then printed.
## Features
- Bounded string input (`%19s`) to prevent buffer overflow.
- Character classification via a dedicated `isAlpha` function.
- In-place string modification through pointer traversal.
- Selective conversion: only lowercase letters are changed to uppercase.
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
./lowercase_to_uppercase
```
## Usage Examples
**Conversion Example:**
```text


String lowercase to uppercase changing

Enter your string: hello
Result: HELLO
```
**Mixed Content Example:**
```text


String lowercase to uppercase changing

Enter your string: Hello123!
Result: HELLO123!
```
**Failed Input Error Example:**
```text


String lowercase to uppercase changing

Enter your string: 
[ERROR] Failed to read string.
```