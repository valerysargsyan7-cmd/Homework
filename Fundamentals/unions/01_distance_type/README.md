# Distance Value and Type

A C program demonstrating standard console input processing, enumerations (`typedef enum`), structures (`struct`), unions (`union`), non-negativity validation, and conditional branching to handle distance measurement in meters or centimeters.

## Description

This program lets users choose between measuring distance in meters (`0`) or centimeters (`1`). It uses a custom enumeration `DistanceTypeChoice` to parse the user's unit selection, a structure `MetersCentimeters` to hold unit values, and a union `MetersOrCentimeters` for data storage. Based on the selected choice, the program prompts for the respective distance input, validates that the value is non-negative, and prints the formatted distance value.

## Features

- Custom C typedef enumeration (`typedef enum DistanceTypeChoice`).
- Nested structure and union data representations (`struct MetersCentimeters` and `union MetersOrCentimeters`).
- Interactive command-line menu for unit selection and numeric entry.
- Validation for invalid selection options and negative distance values.
- Precision-formatted floating-point output for meters (`%.2f`) and integer output for centimeters (`%d`).
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
./distance_type
```

## Usage Examples

**Meters Input Example:**

```text
=== Distance Value and Type ===

Choose type of distance (0-meters, 1-centimeters): 0
Enter meters: 12.5

[SUCCESS] Distance in meters: 12.50
```

**Centimeters Input Example:**

```text
=== Distance Value and Type ===

Choose type of distance (0-meters, 1-centimeters): 1
Enter centimeters: 350

[SUCCESS] Distance in centimeters: 350
```

**Negative Distance Error Example:**

```text
=== Distance Value and Type ===

Choose type of distance (0-meters, 1-centimeters): 0
Enter meters: -5
[ERROR] Distance cannot be negative.
```

**Invalid Choice Error Example:**

```text
=== Distance Value and Type ===

Choose type of distance (0-meters, 1-centimeters): 3
[ERROR] Distance type must be 0 or 1.
```