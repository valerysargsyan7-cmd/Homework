# Missing Number
A C program demonstrating array storage, per-element range and duplicate validation, and a sum-based technique to find the single missing number from a sequence of 1 to N.
## Description
This program prompts the user to enter 9 distinct integers between 1 and 10 via standard input (`stdin`), storing them in an array (`arr_mis[9]`) while validating that each value is in range and hasn't already been entered. It then computes the expected sum of 1 through 10 using the arithmetic series formula, subtracts the actual sum of the entered numbers, and reports the difference as the missing number.
## Features
- Array storage for 9 sequential integer inputs.
- Range validation rejecting values outside 1–10.
- Duplicate detection via a nested-loop check against previously entered values.
- Sum-based missing-number calculation using the arithmetic series formula (`n(n+1)/2`).
- Error handling for invalid, out-of-range, or duplicate inputs.
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
./missing_number
```
## Usage Examples
**Missing Number Example:**
```text


Missing Number

Enter 1th number from 1 to 10: 1
Enter 2th number from 1 to 10: 2
Enter 3th number from 1 to 10: 3
Enter 4th number from 1 to 10: 4
Enter 5th number from 1 to 10: 5
Enter 6th number from 1 to 10: 6
Enter 7th number from 1 to 10: 8
Enter 8th number from 1 to 10: 9
Enter 9th number from 1 to 10: 10

Missing number is: 7
```
**Duplicate Number Error Example:**
```text


Missing Number

Enter 1th number from 1 to 10: 1
Enter 2th number from 1 to 10: 2
Enter 3th number from 1 to 10: 3
Enter 4th number from 1 to 10: 4
Enter 5th number from 1 to 10: 5
Enter 6th number from 1 to 10: 6
Enter 7th number from 1 to 10: 8
Enter 8th number from 1 to 10: 9
Enter 9th number from 1 to 10: 9

[ERROR] Duplicate number entered!
```
**Invalid Input Error Example:**
```text


Missing Number

Enter 1th number from 1 to 10: 1
Enter 2th number from 1 to 10: x

[ERROR] Invalid input!
```