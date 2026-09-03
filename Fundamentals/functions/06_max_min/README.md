# Max and Min
A C program demonstrating array storage, interactive console input with validation, and pointer-based output parameters to find the minimum and maximum values in an array.
## Description
This program prompts the user to enter 10 integers sequentially via standard input (`stdin`), storing them in an array (`mima_arr[10]`) while validating each input. It passes the array along with pointers to `min` and `max` into a `max_min` function, which scans the array once and writes the smallest and largest values found through those pointers. The results are then printed.
## Features
- Array storage for 10 sequential integer inputs.
- Interactive per-element console input prompts and validation.
- Pointer-based output parameters (`min`, `max`) to return two computed values from a `void` function.
- Guard against `NULL` pointers or a non-positive array size.
- Single-pass scan to determine both minimum and maximum.
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
./max_min
```
## Usage Examples
**Max and Min Example:**
```text


Max and Min

Enter your 1th number: 3
Enter your 2th number: -7
Enter your 3th number: 15
Enter your 4th number: 2
Enter your 5th number: 9
Enter your 6th number: -1
Enter your 7th number: 20
Enter your 8th number: 4
Enter your 9th number: 8
Enter your 10th number: 6
Min: -7
Max: 20
```
**Invalid Input Error Example:**
```text


Max and Min

Enter your 1th number: 1
Enter your 2th number: 2
Enter your 3th number: x
[ERROR] Invalid input at element 3.
```