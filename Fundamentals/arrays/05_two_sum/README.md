# Two Sum
A C program demonstrating array storage, interactive console input processing with validation, nested `for` loop iteration, and pairwise sum comparison to locate index pairs matching a target value.
## Description
This program prompts the user to enter a target integer and 10 array elements sequentially via standard input (`stdin`). It stores the elements in an array (`numbers[10]`) while performing input validation. Using nested `for` loop iteration, it checks every unique pair of elements to determine whether their sum equals the target value, printing the indexes of each matching pair found.
## Features
- Target and array storage for sequential integer inputs.
- Interactive per-element console input prompts and validation.
- Nested loop pairwise sum comparison against the target.
- Reporting of all matching index pairs found.
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
./two_sum
```
## Usage Examples
**Pair Found Example:**
```text
=== Two Sum ===

Enter target number: 9
Enter element 1: 2
Enter element 2: 7
Enter element 3: 11
Enter element 4: 15
Enter element 5: 3
Enter element 6: 4
Enter element 7: 5
Enter element 8: 6
Enter element 9: 8
Enter element 10: 0

[SUCCESS] Pair found at indexes: 0 and 1
[SUCCESS] Pair found at indexes: 4 and 7
[SUCCESS] Pair found at indexes: 5 and 6
```
**No Pair Found Example:**
```text
=== Two Sum ===

Enter target number: 1000
Enter element 1: 1
Enter element 2: 2
Enter element 3: 3
Enter element 4: 4
Enter element 5: 5
Enter element 6: 6
Enter element 7: 7
Enter element 8: 8
Enter element 9: 9
Enter element 10: 10

[INFO] No pair found.
```
**Invalid Input Error Example:**
```text
=== Two Sum ===

Enter target number: abc
[ERROR] Invalid target.
```