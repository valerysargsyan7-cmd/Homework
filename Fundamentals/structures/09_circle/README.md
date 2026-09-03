# Circle Radius, Surface, Length
A C program demonstrating struct-based storage, input validation, and geometric formulas to compute a circle's surface area and circumference from its radius.
## Description
This program prompts the user to enter a circle's radius via standard input (`stdin`), stored in a `struct Circle`. After validating that the radius is a positive number, it computes the circle's surface area (`π·r²`) and circumference (`2·π·r`) using an approximation of π (`3.14f`), and prints both results.
## Features
- Struct-based storage (`struct Circle`) for the radius.
- Validation rejecting a radius that is zero or negative.
- Surface area calculation (`π·r²`).
- Circumference calculation (`2·π·r`).
- Error handling for invalid or non-numeric radius input.
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
./circle
```
## Usage Examples
**Circle Example:**
```text


Circle radius, surface, length


Enter Circle radius: 5

Surface: 78.50
Length: 31.40
```
**Invalid Radius Example:**
```text


Circle radius, surface, length


Enter Circle radius: 0

[ERROR] Invalid radius!
```
**Invalid Input Error Example:**
```text


Circle radius, surface, length


Enter Circle radius: x
[ERROR] Invalid radius input!
```