# Unique Member of Array
A C program demonstrating array storage, interactive console input with validation, and nested-loop frequency counting to find the single non-duplicated value in an array.
## Description
This program prompts the user to enter 10 integers sequentially via standard input (`stdin`), storing them in an array (`numbers[10]`) while validating each input. It then checks each element by counting how many times it appears in the array, using a nested loop, and reports the first value found to appear exactly once. If every value has a duplicate, it reports that no unique number was found.
## Features
- Array storage for 10 sequential integer inputs.
- Interactive per-element console input prompts and validation.
- Nested-loop frequency counting to determine each value's occurrence count.
- Detection and reporting of the case where no unique value exists.
- Error handling for invalid numeric inputs.
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
./unique_member
```
## Usage Examples
**Unique Number Found Example:**
```text


Unique Member of Array

Enter 1th member of array: 1
Enter 2th member of array: 1
Enter 3th member of array: 2
Enter 4th member of array: 2
Enter 5th member of array: 3
Enter 6th member of array: 4
Enter 7th member of array: 4
Enter 8th member of array: 5
Enter 9th member of array: 5
Enter 10th member of array: 6

Unique number is: 3
```
**No Unique Number Example:**
```text


Unique Member of Array

Enter 1th member of array: 1
Enter 2th member of array: 1
Enter 3th member of array: 2
Enter 4th member of array: 2
Enter 5th member of array: 3
Enter 6th member of array: 3
Enter 7th member of array: 4
Enter 8th member of array: 4
Enter 9th member of array: 5
Enter 10th member of array: 5

[ERROR] Unique number was not found!
```
**Invalid Input Error Example:**
```text


Unique Member of Array

Enter 1th member of array: 1
Enter 2th member of array: x
[ERROR] Invalid input!
```