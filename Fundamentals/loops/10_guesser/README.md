# Shazam
A C program demonstrating a random number generator, a do-while guessing loop, and range validation to build a classic number-guessing game.
## Description
This program generates a random number between 1 and 100 using `rand()`, seeded with the current time. It then repeatedly prompts the user to guess the number via standard input (`stdin`) in a `do-while` loop, rejecting out-of-range guesses and giving "Higher" or "Lower" hints for in-range guesses, until the user guesses correctly.
## Features
- Random target number generation (`rand() % 100 + 1`), seeded with `time(NULL)`.
- `do-while` loop that repeats until the correct guess is made.
- Range validation rejecting guesses outside 1–100, without ending the game.
- "Higher"/"Lower" feedback based on the guess relative to the target.
- Error handling for invalid numeric input.
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
./shazam
```
## Usage Examples
**Shazam Example:**
```text


Shazam

Enter number for guess from 1 to 100: 50

Lower
Enter number for guess from 1 to 100: 25

Higher
Enter number for guess from 1 to 100: 37

Got it!
```
**Out of Range Error Example:**
```text


Shazam

Enter number for guess from 1 to 100: 150

[ERROR] Number must be between 1 and 100!
Enter number for guess from 1 to 100: 
```
**Invalid Input Error Example:**
```text


Shazam

Enter number for guess from 1 to 100: x

[ERROR] Invalid input!
```