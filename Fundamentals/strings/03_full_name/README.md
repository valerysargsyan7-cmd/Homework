# First Name + Last Name

A C program demonstrating string concatenation using `strcat`, bounded console input handling via `scanf`, buffer initialization, and output formatting.

## Description

This program prompts the user to enter their first name and surname separately via standard input (`stdin`). It restricts each input to 19 characters using `%19s` to prevent buffer overflows. After initializing an empty destination buffer (`fullname[0] = '\0'`), it uses `strcat` to concatenate the first name, a space separator, and the surname into a single full name string before displaying the result.

## Features

- Bounded string input using `%19s` specifiers for buffer overflow protection.
- String concatenation via C standard library `strcat`.
- Safe buffer initialization ensuring null-termination.
- Full error checking for user inputs.
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
./fullname_concat
```

## Usage Examples

**Successful Full Name Concatenation Example:**

```text
=== First Name + Last Name ===

Enter your name: John
Enter your surname: Doe

[SUCCESS] Your full name: 'John Doe'
```

**Failed Input Handling Example:**

```text
=== First Name + Last Name ===

Enter your name: 
[ERROR] Failed to read name.
```