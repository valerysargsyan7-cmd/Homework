# Ctrl+C Handling
A C program demonstrating a signal-safe SIGINT handler using the POSIX `signal()` function and a `volatile sig_atomic_t` flag, instead of doing I/O directly inside the handler.
## Description
This program installs a custom handler for `SIGINT` (the signal sent by Ctrl+C) using `signal()`, then loops forever (via `sleep(1)`), waiting to be interrupted. The handler itself only sets a `volatile sig_atomic_t` flag — the only type the C standard guarantees is safe to modify from a signal handler — and the actual message is printed from the main loop once it notices the flag is set, avoiding any non-async-signal-safe function calls (like `printf`) inside the handler itself.
## Features
- Custom signal handling for `SIGINT` via `signal()`.
- Async-signal-safe handler design: the handler only sets a `volatile sig_atomic_t` flag, doing no I/O itself.
- Deferred, safe printing from the main loop based on the flag, rather than from within signal context.
- Error reporting via `perror()` if `signal()` fails to install the handler.
- Infinite `sleep()` loop so the program stays alive to receive the signal repeatedly.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS), since this program uses `<unistd.h>` and `<signal.h>`
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
./ctrlc_handling
```
Since the program loops forever, use a second terminal or a process kill (e.g. `kill -KILL <pid>`) to actually stop it if Ctrl+C is being tested repeatedly.
## Usage Examples
**Ctrl+C Handling Example (run interactively in a terminal):**
```text


Ctrl+C Handling

Press Ctrl+C to test the handler.

You've just pressed Ctrl+C
```