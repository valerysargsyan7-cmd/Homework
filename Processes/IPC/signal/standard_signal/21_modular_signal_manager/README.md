# Modular Signal Manager (Masked Critical Section)
A modular C library project demonstrating signal handler registration combined with dynamic signal masking (`sigfillset`, `sigprocmask`) to create atomic, interrupt-free critical sections.
## Description
This project demonstrates modular signal administration:
1. **Signal Manager Module (`sig_manager.h` / `sig_manager.c`)**: Exposes `register_safe_handler(int sig, void (*handler)(int))` to encapsulate signal registration with error diagnostics.
2. **Atomic Critical Section (`main.c`)**: Inside the handler, `sigfillset(&set)` and `sigprocmask(SIG_BLOCK)` temporarily block all signals during sensitive handling, restoring previous signal masks upon completion (`sigprocmask(SIG_SETMASK)`).
## Project Structure
```text
21_modular_signal_manager/
├── main.c
├── Makefile
├── README.md
├── sig_manager.c
└── sig_manager.h
```
## Features
- Modular signal registration abstraction.
- Critical-section protection using full signal masks (`sigfillset`).
- Async-signal safe notifications via direct `write()` system calls.
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
./modular_signal_manager
```
## Usage Examples
**Modular Signal Manager Output Example:**
```text


Modular Signal Manager (Masked Critical Section)

Registering handler for SIGINT (Ctrl+C)...
Running loop. Press Ctrl+C to trigger handler, or wait for automatic simulation.
Loop step 1/3... (PID: 35100)
Loop step 2/3... (PID: 35100)
Loop step 3/3... (PID: 35100)

Triggering self SIGINT via raise()...

[HANDLER] -> Signal handled inside protected critical section!
Signals handled: 1. Exiting cleanly.
```
