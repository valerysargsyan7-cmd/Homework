# Sorting Even Numbers
A C program demonstrating a two-pointer, in-place partitioning technique to move all even numbers in an array to the front.
## Description
This program prompts the user to enter 5 integers sequentially via standard input (`stdin`), storing them in an array (`nums[5]`) while validating each input. It then partitions the array in place using two pointers — one starting at the front and one at the back — swapping odd/even pairs and advancing the pointers until they meet, so that all even numbers end up before all odd numbers.
## Features
- Array storage for 5 sequential integer inputs.
- Interactive per-element console input prompts and validation.
- Two-pointer, in-place partitioning to group even numbers at the front.
- Correct parity classification for negative numbers as well as positive.
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
./sorting_even
```
## Usage Examples
**Sorting Even Numbers Example:**
```text


Sorting Even Numbers

Enter 1th number for array: 1
Enter 2th number for array: 2
Enter 3th number for array: 3
Enter 4th number for array: 4
Enter 5th number for array: 5

Even numbers moved to the beginning:

4 2 3 1 5 
```
**Invalid Input Error Example:**
```text


Sorting Even Numbers

Enter 1th number for array: 1
Enter 2th number for array: x

[ERROR] Invalid input!
```