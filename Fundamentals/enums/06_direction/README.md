# Direction
A C program demonstrating a typedef'd enum, range validation, and a `switch` statement to select and report a movement direction.
## Description
This program prompts the user to enter a direction choice (0–3) via standard input (`stdin`), corresponding to a `Direction` enum (`NORTH`, `EAST`, `SOUTH`, `WEST`). After validating that the choice is within range, it converts the integer to the enum type and uses a `switch` statement to print the corresponding direction.
## Features
- Typedef'd enum (`Direction`) for readable, named direction values.
- Range validation against the enum's first and last members (`NORTH`, `WEST`).
- Explicit cast from `int` input to the `Direction` enum type.
- `switch` statement covering all enum cases plus a `default` fallback.
- Error handling for invalid or out-of-range direction input.
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
./direction
```
## Usage Examples
**Direction Example:**
```text


Direction


Enter direction for moving 0-NORTH, 1-EAST, 2-SOUTH, 3-WEST: 0

Moving north
```
**Unknown Direction Error Example:**
```text


Direction


Enter direction for moving 0-NORTH, 1-EAST, 2-SOUTH, 3-WEST: 9

[ERROR] Unknown direction!
```
**Invalid Input Error Example:**
```text


Direction


Enter direction for moving 0-NORTH, 1-EAST, 2-SOUTH, 3-WEST: x
[ERROR] Invalid direction input!
```