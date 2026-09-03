# Custom String Utilities Module
A modular C project implementing independent string manipulation functions (`my_strlen`, `my_strchr`) structured as a reusable library module with separate header and implementation files.
## Description
This project demonstrates modular C programming and low-level string traversal algorithms:
1. **`my_strlen(const char *str)`**: Computes string length by iterating byte-by-byte until the null-terminator `\0` without calling external C runtime string functions.
2. **`my_strchr(const char *str, char ch)`**: Searches for the first occurrence of character `ch` within string `str` and returns a pointer to the matching byte (or `NULL` if not found).
## Project Structure
```text
10_custom_string_utilities/
├── main.c
├── Makefile
├── README.md
├── str_utils.c
└── str_utils.h
```
## Features
- Modular multi-file architecture (`str_utils.h` / `str_utils.c`).
- Clean pointer-based string search and character indexing.
- Interactive user testing interface.
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
./custom_string_utilities
```
## Usage Examples
**Custom String Utilities Output Example:**
```text


Custom String Utilities Module

Enter a string: programming

The length of string is: 11
Enter the letter you want to find: g

[SUCCESS] Letter found! Substring from character: "gramming"
```
