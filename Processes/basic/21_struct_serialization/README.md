# Binary Struct Serialization & Deserialization
A C program demonstrating binary struct file persistence using `fwrite()` and struct deserialization using `fread()`.
## Description
This program demonstrates binary data storage in C:
1. Prompts the user to populate an array of `struct Product` instances (`id`, `size`, `price`).
2. `save_products()` writes the raw struct binary memory blocks to `Products.bin` using `fwrite()`.
3. `load_products()` opens the file in binary read mode (`"rb"`), deserializes each `struct Product` with `fread()`, and prints the parsed fields to stdout.
## Features
- Interactive struct array data input with input validation.
- Block-level binary serialization via `fwrite()`.
- Iterative record deserialization via `fread()`.
- Standard C17 compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
## Building
To compile the project, run:
```bash
make
```
To clean up built binaries and generated binary data files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./struct_serialization
```
## Usage Examples
**Struct Serialization Output Example:**
```text


Binary Struct Serialization & Deserialization

Enter information for 3 products:

Product 1 ID: 101
Product 1 Size: 5
Product 1 Price: 19.99

Product 2 ID: 102
Product 2 Size: 8
Product 2 Price: 49.50

Product 3 ID: 103
Product 3 Size: 12
[WARNING] Size exceeds standard threshold (> 10).
Product 3 Price: 99.00

Info saving status: DONE (3 records written)

--- Reading Saved Products from Binary File ---
ID: 101 | Price: 19.99 | Size: 5
ID: 102 | Price: 49.50 | Size: 8
ID: 103 | Price: 99.00 | Size: 12

Work status: DONE
```
