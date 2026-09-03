# Traffic Signal Controller

A simple C program demonstrating custom typedef enumerations (`typedef enum`), integer input parsing, range validation, and `switch` control flow to emulate a traffic light response system.

## Description

This program defines a custom `Signal` enumeration type representing traffic light states: `RED` (0), `YELLOW` (1), and `GREEN` (2). It prompts the user for an integer signal input from standard input (`stdin`), validates that the entry lies within the zero-indexed bounds of 0 to 2, and explicitly casts the value to the `Signal` enumeration type. A `switch` block evaluates the state and outputs the corresponding directive ("Wait...", "Get ready.", or "GO!").

## Features

- Custom C typedef enumeration type (`typedef enum Signal`).
- Interactive command-line prompt for traffic signal states.
- Input validation catching non-numeric entries and out-of-bounds values (`0 <= signal_input <= 2`).
- Explicit integer-to-enumeration type conversion (`(Signal)signal_input`).
- Switch-case logic for conditional program branching.
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
./traffic_signal
```

## Usage Examples

**Green Signal Example:**

```text
=== Traffic Signal ===

Enter signal (RED-0, YELLOW-1, GREEN-2): 2

[SUCCESS] GO!
```

**Yellow Signal Example:**

```text
=== Traffic Signal ===

Enter signal (RED-0, YELLOW-1, GREEN-2): 1

[INFO] Get ready.
```

**Red Signal Example:**

```text
=== Traffic Signal ===

Enter signal (RED-0, YELLOW-1, GREEN-2): 0

[INFO] Wait...
```

**Out of Range Error Example:**

```text
=== Traffic Signal ===

Enter signal (RED-0, YELLOW-1, GREEN-2): 5
[ERROR] Signal must be 0, 1, or 2.
```

**Invalid Input Type Example:**

```text
=== Traffic Signal ===

Enter signal (RED-0, YELLOW-1, GREEN-2): abc
[ERROR] Invalid signal.
```