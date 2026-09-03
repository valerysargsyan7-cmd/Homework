# Descending Order
A C program demonstrating array storage, interactive console input with validation, and an adjacent-pair scan to check whether an array is sorted in descending order.
## Description
This program prompts the user to enter 10 integers sequentially via standard input (`stdin`), storing them in an array (`arr_des_ord[10]`) while validating each input. It then scans the array, comparing each element to the one before it, and reports `YES` if no element is greater than its predecessor (allowing equal values), or `NO` as soon as an increase is found.
## Features
- Array storage for 10 sequential integer inputs.
- Interactive per-element console input prompts and validation.
- Adjacent-pair scan with early exit on the first out-of-order pair.
- Equal consecutive values are treated as still descending (non-strict order check).
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
./descending_order
```
## Usage Examples
**Descending Order Example:**
```text


Descending Order

Enter 1th number: 10
Enter 2th number: 9
Enter 3th number: 8
Enter 4th number: 7
Enter 5th number: 6
Enter 6th number: 5
Enter 7th number: 4
Enter 8th number: 3
Enter 9th number: 2
Enter 10th number: 1

YES
```
**Not Descending Example:**
```text


Descending Order

Enter 1th number: 10
Enter 2th number: 9
Enter 3th number: 8
Enter 4th number: 7
Enter 5th number: 6
Enter 6th number: 5
Enter 7th number: 4
Enter 8th number: 3
Enter 9th number: 2
Enter 10th number: 5

NO
```
**Invalid Input Error Example:**
```text


Descending Order

Enter 1th number: 1
Enter 2th number: x

[ERROR] Invalid input!
```