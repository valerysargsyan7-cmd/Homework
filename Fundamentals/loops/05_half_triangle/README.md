# Half Triangle
A C program demonstrating nested `for` loop iteration and conditional printing to draw a right-aligned half triangle of a chosen size and symbol.
## Description
This program prompts the user to enter a triangle size (quantity) and a symbol to build it with, via standard input (`stdin`). Using nested `for` loops, it prints one row per level: leading spaces followed by an increasing number of the chosen symbol, forming a right-aligned half triangle.
## Features
- Interactive console input for triangle size and build symbol.
- Validation that the quantity is a positive integer greater than zero.
- Nested-loop row-by-row rendering with conditional space/symbol printing.
- Error handling for invalid quantity or symbol inputs.
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
./half_triangle
```
## Usage Examples
**Half Triangle Example:**
```text


Half triangle

Enter quantity: 5
Enter symbol for building triangle: *
    *
   **
  ***
 ****
*****
```
**Invalid Quantity Error Example:**
```text


Half triangle

Enter quantity: 0
[ERROR] Quantity must be greater than zero.
```
**Invalid Quantity Input Error Example:**
```text


Half triangle

Enter quantity: x
[ERROR] Invalid quantity input. Please enter an integer.
```