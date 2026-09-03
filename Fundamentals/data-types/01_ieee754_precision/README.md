# IEEE 754 Precision Comparison

A simple C program demonstrating precision differences between single-precision (`float`) and double-precision (`double`) floating-point types according to the IEEE 754 standard.

## Description

This program divides the integer `1` by `3` using single-precision floating-point arithmetic (`1.0f / 3.0f`) and double-precision floating-point arithmetic (`1.0 / 3.0`). It prints both values to 15 decimal places of precision using formatted `printf` output to highlight the difference in mantissa precision and rounding artifacts between 32-bit `float` and 64-bit `double` types.

## Features

- Non-interactive demonstration of IEEE 754 floating-point precision differences.
- Comparison of single-precision (`float`) and double-precision (`double`) floating-point representation.
- Formatted output using `%.15f` specifier to highlight precision loss.
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
./ieee754_precision
```

## Usage Example

**Program Execution Output:**

```text
IEEE 754 precision

Float value:  0.333333343267441
Double value: 0.333333333333333
```