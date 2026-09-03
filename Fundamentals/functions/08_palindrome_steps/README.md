# Palindrome Steps
A C program demonstrating overflow-safe integer reversal via an explicit output parameter, an iterative reverse-and-add algorithm, and a step-count safety cap to find how many iterations it takes a number to become a palindrome.
## Description
This program prompts the user to enter an integer via standard input (`stdin`). It repeatedly reverses the digits of the number and adds the reversal to it, checking after each step whether the result is a palindrome, using the classic "reverse and add" technique. The digit-reversal step reports overflow through an explicit `overflowed` output parameter rather than an ambiguous return value, so it stops and reports an error immediately if the reversal or the addition would overflow a signed `int`, or if it hasn't converged after 10000 steps. Otherwise, it prints how many steps were needed and the resulting palindrome.
## Features
- Overflow-safe digit reversal (`reversing_number`) that checks bounds against `INT_MAX` before each multiplication.
- Explicit `overflowed` output parameter so a reversal of `0` can never be confused with an overflow.
- Iterative reverse-and-add loop via a separate `palindrome_step` function.
- Pointer-based output parameters (`steps`, `final_palindrome`) to return two computed values from a `void` function.
- Overflow guard on the addition step to avoid signed integer overflow.
- Step-count safety cap (10000 iterations) to avoid an unbounded loop on numbers that never converge.
- Handling of negative input by using its absolute value.
- Error handling for invalid numeric input and for unsafe/non-converging computations.
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
./palindrome_steps
```
## Usage Examples
**Palindrome Found Example:**
```text


Palindrome steps

Enter your number: 87
Steps: 4
Palindrome: 4884
```
**Already a Palindrome Example:**
```text


Palindrome steps

Enter your number: 121
Steps: 0
Palindrome: 121
```
**Overflow / Non-Converging Example:**
```text


Palindrome steps

Enter your number: 196
[ERROR] Could not find palindrome safely.
```
**Invalid Input Error Example:**
```text


Palindrome steps

Enter your number: x
[ERROR] Invalid input. Please enter an integer.
```