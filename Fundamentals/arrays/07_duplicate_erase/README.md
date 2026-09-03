# Erasing Duplicates
A C program demonstrating array storage, interactive console input with validation, and nested-loop duplicate detection to reduce an array to its unique values.
## Description
This program prompts the user to enter 10 integers sequentially via standard input (`stdin`), storing them in an array (`duplicate[10]`) while validating each input. It then builds the set of unique values in place by checking each element against the ones already confirmed unique, using a nested loop, and prints the resulting deduplicated list.
## Features
- Array storage for 10 sequential integer inputs.
- Interactive per-element console input prompts and validation.
- Nested-loop duplicate detection against previously confirmed unique values.
- In-place reduction of the array to its unique elements.
- Error handling for invalid or non-numeric inputs.
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
./erasing_duplicates
```
## Usage Examples
**Erasing Duplicates Example:**
```text


Erasing duplicates

Enter your 1th number: 1
Enter your 2th number: 2
Enter your 3th number: 2
Enter your 4th number: 3
Enter your 5th number: 4
Enter your 6th number: 3
Enter your 7th number: 5
Enter your 8th number: 1
Enter your 9th number: 6
Enter your 10th number: 7
Result: 1 2 3 4 5 6 7 
```
**Invalid Input Error Example:**
```text


Erasing duplicates

Enter your 1th number: 1
Enter your 2th number: abc
[ERROR] Invalid input. Please enter an integer.
```