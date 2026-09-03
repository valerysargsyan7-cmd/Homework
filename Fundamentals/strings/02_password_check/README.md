# Password Check

A C program demonstrating string comparison using `strcmp`, secure input reading via `scanf` buffer bounds, constant string storage, and access control branching.

## Description

This program prompts the user to enter a password via standard input (`stdin`). It restricts input length to 19 characters using `%19s` to prevent buffer overflow vulnerabilities. The entered password is compared against a pre-defined constant target string (`"Password"`) using the standard library `strcmp` function. Depending on whether the string evaluation returns `0` (exact match), access is either granted or denied.

## Features

- String equality comparison using standard C library `strcmp`.
- Bounded input reading with `%19s` buffer protection.
- Constant target string declaration (`const char password[]`).
- Input acquisition error handling and execution branching.
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
./password_check
```

## Usage Examples

**Access Granted Example:**

```text
=== Password Check ===

Enter password: Password

[SUCCESS] ACCESS GRANTED
```

**Access Denied Example:**

```text
=== Password Check ===

Enter password: WrongPassword

[ERROR] ACCESS DENIED
```

**Failed Input Handling Example:**

```text
=== Password Check ===

Enter password:
[ERROR] Failed to read password.
```