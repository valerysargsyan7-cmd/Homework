# Is Prime
A C program demonstrating pointer arithmetic for array access, a trial-division primality check, and interactive per-element classification of input numbers.
## Description
This program prompts the user to enter 10 integers sequentially via standard input (`stdin`), accessing the array through a pointer (`prime_ptr`) rather than array-index syntax. Each number is checked immediately after being read using an `is_prime` function, which performs trial division up to the square root of the number, and prime numbers are printed as they're found.
## Features
- Pointer-based array access (`prime_ptr + i`) instead of `array[i]` indexing.
- Interactive per-element console input prompts and validation.
- Trial-division primality check bounded by `i <= n / i` (equivalent to checking up to √n).
- Immediate per-element classification and reporting as input is read.
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
./is_prime
```
## Usage Examples
**Is Prime Example:**
```text


Is Prime

Enter your 1th number: 2
Prime: 2
Enter your 2th number: 3
Prime: 3
Enter your 3th number: 4
Enter your 4th number: 5
Prime: 5
Enter your 5th number: 9
Enter your 6th number: 11
Prime: 11
Enter your 7th number: 15
Enter your 8th number: 17
Prime: 17
Enter your 9th number: 20
Enter your 10th number: 23
Prime: 23
```
**Invalid Input Error Example:**
```text


Is Prime

Enter your 1th number: 1
Enter your 2th number: x
[ERROR] Invalid input at element 2.
```