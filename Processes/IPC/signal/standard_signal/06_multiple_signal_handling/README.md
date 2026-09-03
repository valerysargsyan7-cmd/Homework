# Multiple Signal Handling
A C program demonstrating a single multiplexed signal handler capable of handling multiple distinct POSIX signals (`SIGINT`, `SIGTERM`, `SIGUSR1`).
## Description
This program registers a single handler function (`several_sig_handler`) across three standard signals: `SIGINT` (interruption), `SIGTERM` (termination request), and `SIGUSR1` (user-defined signal 1). When any of these signals are delivered, the signal number is captured safely via a `volatile sig_atomic_t` variable, and the main loop dispatches and prints the corresponding response using a `switch` statement without terminating the process.
## Features
- Single multiplexed handler registered for `SIGINT`, `SIGTERM`, and `SIGUSR1`.
- Async-signal-safe state capture using `volatile sig_atomic_t`.
- Signal-specific branch handling via `switch`.
- Error checking on `signal()` registration.
- Standard C17 and POSIX compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS)
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
./multiple_signal_handling
```
To test signal delivery from another terminal:
```bash
kill -USR1 <pid>
kill -TERM <pid>
```
## Usage Examples
**Multiple Signal Handling Example:**
```text


Handling Different Signals

Process PID: 12345
Listening for SIGINT (Ctrl+C), SIGTERM, and SIGUSR1...

Ctrl+C pressed, but i won't stop!

Custom user signal received!

Termination request received, ignoring!
```
