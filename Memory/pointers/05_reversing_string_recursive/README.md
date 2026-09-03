# Reversing String
A C program demonstrating recursion to print a string in reverse, printing characters on the way back out of the call stack rather than storing a reversed copy.
## Description
This program prompts the user to enter a string (up to 49 characters) via standard input (`stdin`). It reverses the string recursively — a `reversing_string` function that recurses to the end of the string first, then prints each character as the recursive calls return, producing the string in reverse order without allocating a second buffer.
## Features
- Bounded string input (`%49s`) to prevent buffer overflow.
- Recursive traversal via pointer advancement (no index variables).
- Reversed output achieved by printing after the recursive call, not before.
- No second buffer used to store the reversed string.
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


Reversing String


Enter string: hello

Reversed string: olleh
```
**Failed Input Error Example:**
```text


Reversing String


Enter string: [ERROR] Failed to read string!
```