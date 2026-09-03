# Run Length Encode
A C program demonstrating a custom string-copy helper and run-length encoding of consecutive repeated characters.
## Description
This program prompts the user to enter three strings (up to 99 characters each) via standard input (`stdin`). Each string is run-length encoded — replacing consecutive runs of the same character with that character followed by its repeat count — using a `run_length_encode` function that first copies the input into a working buffer via a custom `my_strcpy` helper, then scans and writes the encoded result. Each original and encoded string is printed.
## Features
- Custom string-copy helper (`my_strcpy`) implemented from scratch, without `<string.h>`'s `strcpy`.
- Run-length encoding of consecutive repeated characters into a `char + count` format.
- Bounded string input (`%99s`) to prevent buffer overflow.
- Processes and reports on three separate strings in sequence.
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
./run_length_encode
```
## Usage Examples
**Run Length Encode Example:**
```text


Run Length Encode


Enter symbols to count for first: aaabbbcc

Enter symbols to count for second: wwwwww

Enter symbols to count for third: abcdef

Before counting: aaabbbcc
After counting: a3b3c2

Before counting: wwwwww
After counting: w6

Before counting: abcdef
After counting: a1b1c1d1e1f1
```
**Failed Input Error Example:**
```text


Run Length Encode


Enter symbols to count for first: [ERROR] Failed to read first string!
```