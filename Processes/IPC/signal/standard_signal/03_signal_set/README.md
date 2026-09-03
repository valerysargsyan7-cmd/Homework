# Signal Set
A C program demonstrating POSIX signal sets — building a set of signals and checking membership in it.
## Description
This program builds an empty POSIX signal set using `sigemptyset()`, adds `SIGINT` to it with `sigaddset()`, and then checks membership in that set for both `SIGINT` and `SIGTERM` using `sigismember()`, printing whether each one is present.
## Features
- Signal set initialization via `sigemptyset()`.
- Adding a signal to a set via `sigaddset()`.
- Membership testing via `sigismember()`, demonstrated for both a signal that is and isn't in the set.
- Error reporting via `perror()` if `sigemptyset()` or `sigaddset()` fail.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS), since this program uses `<signal.h>`'s POSIX signal-set functions
## Building
To compile the project, run:
```bash
make
```
To clean up built binaries:
```bash
make clean
```
Note: `sigset_t` and the signal-set functions require `_POSIX_C_SOURCE` to be defined to be visible under strict `-std=c17`; the Makefile sets this via `-D_POSIX_C_SOURCE=200809L`.
## Running
Run the compiled executable:
```bash
./signal_set
```
## Usage Examples
**Signal Set Example:**
```text


Signal Set


SIGINT EXISTS

SIGTERM DOESN'T EXIST
```