# Modular Signal Ping-Pong (SIGUSR1)
A modular C library project demonstrating bidirectional inter-process signal coordination using `SIGUSR1` and clean event waiting via `pause()`.
## Description
This project demonstrates modular IPC signal encapsulation:
1. **Ping-Pong Library (`ping_pong.h` / `ping_pong.c`)**:
   - `wait_ping()`: Configures a `SIGUSR1` handler with atomic flag capture and suspends execution with `pause()` until notified.
   - `send_ping(pid_t target)`: Transmits `SIGUSR1` to the target process ID via `kill()`.
2. **Driver (`main.c`)**: Creates a child process that waits for incoming pings while the parent delivers the signal payload, completing the synchronization cycle.
## Project Structure
```text
20_modular_signal_ping_pong/
├── main.c
├── Makefile
├── ping_pong.c
├── ping_pong.h
└── README.md
```
## Features
- Modular abstraction of signal sending and waiting functions.
- Async-signal safe atomic flag usage (`volatile sig_atomic_t`).
- Low-power process suspension with `pause()`.
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
./modular_signal_ping_pong
```
## Usage Examples
**Modular Signal Ping-Pong Output Example:**
```text


Modular Signal Ping-Pong (SIGUSR1)

[PARENT] -> Sleeping 1 second before sending ping to child (PID: 34102)...
[CHILD] -> Waiting for signal ping from parent...
[PARENT] -> Sending ping (SIGUSR1) via send_ping()...
[CHILD] -> Signal ping received! (Pong returned).
[PARENT] -> Ping-pong exchange complete.
```
