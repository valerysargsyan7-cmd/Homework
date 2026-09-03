# The Most Popular Symbol in String
A C program demonstrating bounded string input, frequency counting via an index array, and a running-maximum scan to find the most frequent lowercase letter in a string.
## Description
This program prompts the user to enter a lowercase string (up to 19 characters) via standard input (`stdin`). It counts the occurrences of each lowercase letter using a 26-element frequency array indexed by `letter - 'a'`, tracking the most frequent letter as it scans. It then prints the most popular symbol and how many times it occurred, or reports if no lowercase letters were found.
## Features
- Bounded string input (`%19s`) to prevent buffer overflow.
- Frequency counting of lowercase letters via a 26-element array.
- Running-maximum tracking to identify the most popular symbol in a single pass.
- Handling of strings with no lowercase letters.
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
./popular_symbol
```
## Usage Examples
**Popular Symbol Found Example:**
```text


The most popular symbol in string

Enter your string in lowercase: banana
Most popular symbol: a
Number of occurrences: 3
```
**No Lowercase Letters Example:**
```text


The most popular symbol in string

Enter your string in lowercase: 12345
No lowercase letters found.
```
**Invalid Input Error Example:**
```text


The most popular symbol in string

Enter your string in lowercase: 
Error: Invalid input.
```