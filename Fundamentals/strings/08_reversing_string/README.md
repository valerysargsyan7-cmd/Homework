# Reversing String
A C program demonstrating bounded string input, string reversal via indexed iteration, and fixed-size character array storage.
## Description
This program prompts the user to enter a string (up to 19 characters) via standard input (`stdin`), storing it in a fixed-size character array (`reversing_string[20]`). It builds a reversed copy of the string by iterating over its characters in reverse index order, storing the result in a second array (`reversed_string[20]`), and prints the reversed string.
## Features
- Bounded string input (`%19s`) to prevent buffer overflow.
- Fixed-size character array storage for the original and reversed strings.
- Indexed reverse-order copying to build the reversed string.
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


Reversing string

Enter your string: hello

Reversed: olleh
```
**Invalid Input Error Example:**
```text


Reversing string

Enter your string: 
[ERROR] Invalid input.
```