# Temperature Conversion (Celsius to Fahrenheit)

A simple C program demonstrating standard input handling, input validation, and floating-point arithmetic to convert temperatures from Celsius to Fahrenheit.

## Description

This program prompts the user to enter a temperature in degrees Celsius from standard input (`stdin`). It validates the input to ensure numeric data is provided, calculates the equivalent temperature in Fahrenheit using the conversion formula `fahrenheit = celsius * 1.8 + 32`, and displays the result formatted to two decimal places.

## Features

- Interactive command-line prompt for Celsius temperature input.
- Input validation to catch non-numeric entries.
- Floating-point arithmetic conversion.
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
./temp_conversion
```

## Usage Examples

**Valid Input Example:**

```text
Temperature conversion

Enter temperature (Celsius): 25

Temperature: 77.00 Fahrenheit
```

**Negative Temperature Example:**

```text
Temperature conversion

Enter temperature (Celsius): -40

Temperature: -40.00 Fahrenheit
```

**Invalid Input Example:**

```text
Temperature conversion

Enter temperature (Celsius): abc
Error: Invalid input. Please enter a valid temperature.
```