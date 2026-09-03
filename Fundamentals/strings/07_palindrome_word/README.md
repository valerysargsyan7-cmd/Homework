# Palindrome Word
A C program demonstrating fixed-size character array storage, bounded string input, string reversal via indexed iteration, and string comparison to detect palindromes.
## Description
This program prompts the user to enter a word (up to 9 characters) via standard input (`stdin`), storing it in a fixed-size character array (`palindrome_word[10]`). It builds a reversed copy of the word by iterating over its characters in reverse index order, then compares the original and reversed strings using `strcmp` to determine whether the word is a palindrome.
## Features
- Bounded string input (`%9s`) to prevent buffer overflow.
- Fixed-size character array storage for word and its reversal.
- Indexed reverse-order copying to build the reversed word.
- String comparison via `strcmp` to detect palindromes.
- Error handling for failed input reads.
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
./palindrome_word
```
## Usage Examples
**Palindrome Example:**
```text
=== Palindrome Word ===

Enter your word: level

[SUCCESS] YES — the word is a palindrome.
```
**Non-Palindrome Example:**
```text
=== Palindrome Word ===

Enter your word: hello

[INFO] NO — the word is not a palindrome.
```
**Failed Input Example:**
```text
=== Palindrome Word ===

Enter your word: 
[ERROR] Failed to read the word.
```