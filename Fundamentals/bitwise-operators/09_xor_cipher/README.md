# XOR Cipher

A simple C program demonstrating symmetric data encryption and decryption using the bitwise XOR (`^`) operator and standard console input validation.

## Description

This program prompts the user to enter integer values for secret data and an encryption key from standard input (`stdin`). It validates both inputs to ensure numeric values are provided, computes the ciphertext using the XOR operation (`cipher = secret_data ^ key`), and recovers the original data by applying XOR with the same key (`decrypted_data = cipher ^ key`).

## Features

- Interactive command-line prompts for secret data and key.
- Input validation catching non-integer inputs.
- Symmetric encryption and decryption using the bitwise XOR (`^`) operator.
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
./xor_cipher
```

## Usage Examples

**Encryption and Decryption Example:**

```text
XOR cipher

Enter secret data: 12345
Enter key: 888

Encrypted data: 11529
Decrypted data: 12345
```

**Zero Key Example:**

```text
XOR cipher

Enter secret data: 42
Enter key: 0

Encrypted data: 42
Decrypted data: 42
```

**Invalid Input Example:**

```text
XOR cipher

Enter secret data: abc
Error: Invalid secret data.
```