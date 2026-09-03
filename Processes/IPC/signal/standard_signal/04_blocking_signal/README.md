# Blocking Signal
A C program demonstrating POSIX signal blocking by preventing `SIGINT` from being delivered for a limited period of time.

## Description

This program creates a POSIX signal set, adds `SIGINT` to it, and blocks the signal using `sigprocmask()` with `SIG_BLOCK`. The program then waits for 6 seconds while `SIGINT` remains blocked.

During this period, pressing `Ctrl+C` does not terminate the program immediately because `SIGINT` is blocked. After 6 seconds, the program prints a completion message and exits.

## Features

- POSIX signal set initialization via `sigemptyset()`.
- Adding `SIGINT` to the signal set via `sigaddset()`.
- Blocking `SIGINT` using `sigprocmask()` with `SIG_BLOCK`.
- Demonstration of a temporary signal-blocking period using `sleep()`.
- Error reporting via `perror()` if signal-set operations or signal blocking fail.

## Requirements

- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS), since this program uses POSIX signal APIs

## Building

To compile the project, run:

```bash
make
````

To clean up the built binary:

```bash
make clean
```

Note: POSIX signal-set types and functions require `_POSIX_C_SOURCE` to be defined to be visible under strict `-std=c17`; the Makefile sets this via `-D_POSIX_C_SOURCE=200809L`.

## Running

Run the compiled executable:

```bash
./blocking_signal
```

## Usage Examples

**Blocking Signal Example:**

```text


Blocking Signal


SIGINT is blocked for 6 seconds.
Try pressing Ctrl+C.

6 seconds finished.
Program is ending.
```

If `Ctrl+C` is pressed while `SIGINT` is blocked, the program does not terminate during the 6-second blocking period.

```
