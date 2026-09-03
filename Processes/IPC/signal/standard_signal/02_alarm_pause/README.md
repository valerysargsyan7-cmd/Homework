# Alarm Pause
A C program demonstrating a signal-safe SIGALRM handler, using the POSIX `alarm()` and `pause()` functions to wait for a timed signal without calling non-async-signal-safe functions inside the handler itself.
## Description
This program installs a custom handler for `SIGALRM` using `signal()`, schedules an alarm to fire after 4 seconds via `alarm(4)`, and suspends execution with `pause()` until a signal arrives. The handler itself only sets a `volatile sig_atomic_t` flag — the only type the C standard guarantees is safe to modify from a signal handler — and `main()` checks that flag right after `pause()` returns to print the actual message, avoiding any I/O inside the handler.
## Features
- Custom signal handling for `SIGALRM` via `signal()`.
- Timed signal delivery via `alarm()`.
- Process suspension until signal delivery via `pause()`.
- Async-signal-safe handler design: the handler only sets a `volatile sig_atomic_t` flag, doing no I/O itself.
- Error reporting via `perror()` if `signal()` fails to install the handler.
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
./alarm_pause
```
The program will wait about 4 seconds before finishing.
## Usage Examples
**Alarm Pause Example:**
```text


Alarm Pause

Waiting for alarm...

Time is up!
Program finished.
```