# SIGINT Emergency Logger
A C program demonstrating async-signal-safe emergency file logging upon receipt of a `SIGINT` (Ctrl+C) signal.
## Description
This program demonstrates capturing unexpected termination events and logging an emergency shutdown message before the process exits. A custom handler is installed for `SIGINT`. When the user presses Ctrl+C, the handler executes low-level, async-signal-safe POSIX system calls (`open`, `write`, `close`, `_exit`) to append an audit entry (`"[CRITICAL] Emergency stop applied!\n"`) into `SIGINT_info.txt` and terminates cleanly.
## Features
- Signal handler installation for `SIGINT`.
- Low-level emergency disk logging within signal context.
- Use of async-signal-safe POSIX system calls (`open`, `write`, `close`, `_exit`).
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
To clean up built binaries and created log files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./sigint_emergency_logger
```
## Usage Examples
**SIGINT Emergency Logger Output Example:**
```text


SIGINT Emergency Logger

Running... Press Ctrl+C to trigger emergency stop logging.
^C
[CRITICAL] Emergency stop applied! Logged to SIGINT_info.txt.
```
