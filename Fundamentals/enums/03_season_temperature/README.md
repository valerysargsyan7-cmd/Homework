# Season Temperature Range

A simple C program demonstrating custom enumeration (`enum`), input validation, explicit type casting, and `switch` statement control flow to display average temperature ranges based on the selected season.

## Description

This program defines a custom `enum Season` representing the four annual seasons: `SPRING` (0), `SUMMER` (1), `AUTUMN` (2), and `WINTER` (3). It presents an interactive menu to prompt the user for a season choice via standard input (`stdin`), validates that the selection falls strictly within the defined range, and explicitly casts the value to the `enum Season` type. A `switch` block evaluates the enumeration value and prints the corresponding temperature range in Celsius.

## Features

- Custom C enumeration type definition (`enum Season`).
- Interactive command-line menu prompting for season selections.
- Input validation catching non-numeric entries and out-of-bounds choices (`0 <= season_input <= 3`).
- Explicit integer-to-enumeration type conversion (`(enum Season)season_input`).
- Switch-case control structure for conditional output branching.
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
./season_temperature
```

## Usage Examples

**Summer Season Example:**

```text
=== Season Temperature ===

Choose a season:
  0 - Spring
  1 - Summer
  2 - Autumn
  3 - Winter

Enter your choice: 1

[INFO] Temperature range: +16 to +40 C
```

**Winter Season Example:**

```text
=== Season Temperature ===

Choose a season:
  0 - Spring
  1 - Summer
  2 - Autumn
  3 - Winter

Enter your choice: 3

[INFO] Temperature range: -5 to +6 C
```

**Out of Range Error Example:**

```text
=== Season Temperature ===

Choose a season:
  0 - Spring
  1 - Summer
  2 - Autumn
  3 - Winter

Enter your choice: 4
[ERROR] Invalid season.
```

**Invalid Input Type Example:**

```text
=== Season Temperature ===

Choose a season:
  0 - Spring
  1 - Summer
  2 - Autumn
  3 - Winter

Enter your choice: abc
[ERROR] Invalid input.
```