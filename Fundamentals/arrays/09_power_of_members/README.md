# Array Member's Power
A C program demonstrating array storage, interactive console input with validation, and a separate function to compute the square of each array element into a new array.
## Description
This program prompts the user to enter 10 integers sequentially via standard input (`stdin`), storing them in an array (`powering_arr[10]`) while validating each input. It passes the array into a `square_elements` function, which computes the square of each element and writes the results into a second array (`powered_arr[10]`), leaving the original array unchanged. The squared array is then printed.
## Features
- Array storage for 10 sequential integer inputs.
- Interactive per-element console input prompts and validation.
- Separate output array for squared values, leaving the original array untouched.
- Element-wise squaring via a dedicated function.
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
./array_power
```
## Usage Examples
**Array Power Example:**
```text


Array Member's Power

Enter 1th number: 1
Enter 2th number: 2
Enter 3th number: 3
Enter 4th number: 4
Enter 5th number: 5
Enter 6th number: -1
Enter 7th number: -2
Enter 8th number: 0
Enter 9th number: 10
Enter 10th number: -10

Powered array:
1 4 9 16 25 1 4 0 100 100 
```
**Invalid Input Error Example:**
```text


Array Member's Power

Enter 1th number: 1
Enter 2th number: x
[ERROR] Invalid input!
```