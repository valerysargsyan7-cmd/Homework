# Password Checking

A simple C program demonstrating constant variable declarations, standard console input handling, input validation, and security access verification logic.

## Description

This program prompts the user to enter a numeric password from standard input (`stdin`). It validates the input format to ensure an integer is provided and compares the input against a hardcoded constant password (`4554`). If the password matches, it outputs "ACCESS GRANTED"; otherwise, it outputs "ACCESS DENIED".

## Features

- Interactive command-line prompt for password entry.
- Input validation catching non-integer input.
- Constant variable declaration (`const int password`).
- Conditional branching for access authorization.
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
./password_checker
```

## Usage Examples

**Access Granted Example:**

```text
Password checking

Enter password: 4554

ACCESS GRANTED
```

**Access Denied Example:**

```text
Password checking

Enter password: 1234

ACCESS DENIED
```

**Invalid Input Example:**

```text
Password checking

Enter password: abc
Error: Invalid password input.
```