# Moving Zeros
A C program demonstrating array storage, interactive console input with validation, in-place partitioning via indexed iteration, and zero-padding to move all zero values to the end of an array.
## Description
This program prompts the user to enter 10 integers sequentially via standard input (`stdin`), storing them in an array (`arr_with_zeros[10]`) while validating each input. It then moves all non-zero values to the front of the array in their original relative order, using a write-pointer technique, and fills the remaining positions with zeros. The final array is printed as the result.
## Features
- Array storage for 10 sequential integer inputs.
- Interactive per-element console input prompts and validation.
- In-place partitioning of non-zero values using a write-pointer index.
- Zero-padding of remaining array positions after partitioning.
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
./moving_zeros
```
## Usage Examples
**Moving Zeros Example:**
```text


Moving zeros

Enter your 1th number: 0
Enter your 2th number: 1
Enter your 3th number: 0
Enter your 4th number: 3
Enter your 5th number: 12
Enter your 6th number: 0
Enter your 7th number: 5
Enter your 8th number: 0
Enter your 9th number: 0
Enter your 10th number: 7

Result:
1 3 12 5 7 0 0 0 0 0 
```
**Invalid Input Error Example:**
```text


Moving zeros

Enter your 1th number: 1
Enter your 2th number: abc

[ERROR] Invalid input. Please enter a valid integer.
```