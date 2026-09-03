# FizzBuzz
A C program demonstrating range-based console input with validation and a classic FizzBuzz loop over a user-defined range.
## Description
This program prompts the user to enter two integers defining a range (first and second), via standard input (`stdin`), validating that the first is not greater than the second. It then prints each number in the range, replacing multiples of 3 with "FIZZ", multiples of 5 with "BUZZ", and multiples of both with "FIZZBUZZ".
## Features
- Interactive console input for a range with validation.
- Range-order validation (first number must not exceed second number).
- Classic FizzBuzz classification using modulo checks (`%15`, `%3`, `%5`).
- Error handling for invalid numeric input or an invalid range.
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
./fizzbuzz
```
## Usage Examples
**FizzBuzz Example:**
```text


FizzBuzz

Enter diapason first number: 1
Enter diapason second number: 15
1
2
FIZZ
4
BUZZ
FIZZ
7
8
FIZZ
BUZZ
11
FIZZ
13
14
FIZZBUZZ
```
**Invalid Range Error Example:**
```text


FizzBuzz

Enter diapason first number: 10
Enter diapason second number: 5
[ERROR] First number must be less than or equal to second number.
```
**Invalid Input Error Example:**
```text


FizzBuzz

Enter diapason first number: x
[ERROR] Invalid input for first number.
```