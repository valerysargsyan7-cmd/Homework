# Moving by Coordinates

A C program demonstrating custom structure (`struct`) definition, enumeration (`enum`) command flags, infinite loop control flow (`while(1)`), interactive console input validation, and 2D coordinate manipulation using `switch` branching.

## Description

This program tracks a 2D point `(x, y)` initialized at `(0, 0)` using a custom `struct Point`. It continuously prompts the user to input directional commands mapped to an `enum Direction` (`STOP`, `NORTH`, `SOUTH`, `EAST`, `WEST`). Based on the selected direction, the program updates the spatial coordinates accordingly and outputs the updated position. Entering `0` terminates the application gracefully.

## Features

- Custom C structure (`struct Point`) encapsulating `x` and `y` Cartesian coordinates.
- Enumeration (`enum Direction`) defining explicit numerical command mappings.
- Interactive infinite loop menu system allowing step-by-step navigation.
- Directional coordinate updating:
  - `NORTH` (`1`): Increments `y`
  - `SOUTH` (`2`): Decrements `y`
  - `EAST` (`3`): Increments `x`
  - `WEST` (`4`): Decrements `x`
- Input validation detecting non-numeric inputs and unsupported option codes.
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
./point_move
```

## Usage Examples

**Coordinate Navigation Example:**

```text
=== Moving by Coordinates ===


  1 - North
  2 - South
  3 - East
  4 - West
  0 - Exit
Enter command: 1

[SUCCESS] Current position: (0, 1)

  1 - North
  2 - South
  3 - East
  4 - West
  0 - Exit
Enter command: 3

[SUCCESS] Current position: (1, 1)

  1 - North
  2 - South
  3 - East
  4 - West
  0 - Exit
Enter command: 0

[INFO] Goodbye!
```

**Unknown Command Example:**

```text
=== Moving by Coordinates ===


  1 - North
  2 - South
  3 - East
  4 - West
  0 - Exit
Enter command: 9
[ERROR] Unknown command.

  1 - North
  2 - South
  3 - East
  4 - West
  0 - Exit
Enter command: 0

[INFO] Goodbye!
```

**Invalid Input Type Example:**

```text
=== Moving by Coordinates ===


  1 - North
  2 - South
  3 - East
  4 - West
  0 - Exit
Enter command: abc
[ERROR] Invalid command.
```