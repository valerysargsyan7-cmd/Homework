# Signal Mask with Alarm Timeout
A C program demonstrating POSIX signal masking to block `SIGINT` (Ctrl+C) while scheduling an asynchronous timer via `alarm()` to terminate the process safely after a timeout.
## Description
This program blocks the delivery of `SIGINT` using `sigprocmask()` with a `sigset_t` containing `SIGINT`. As a result, attempts to interrupt the process using Ctrl+C are blocked and ignored during execution. To guarantee that the process does not remain blocked indefinitely, a 5-second timer is established using `alarm(5)`. When the timer expires, a `SIGALRM` signal is delivered, waking the process from `pause()` and triggering a clean exit.
## Features
- Signal masking and blocking using `sigemptyset()`, `sigaddset()`, and `sigprocmask()`.
- Blocking `SIGINT` (Ctrl+C) from interrupting normal execution.
- Timed process wake-up using `alarm(5)` and `SIGALRM`.
- Low-power waiting via `pause()`.
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
./signal_mask_alarm_timeout
```
## Usage Examples
**Signal Mask with Alarm Timeout Example:**
```text


Immortal Process with Alarm Timeout

Blocking SIGINT (Ctrl+C). Try pressing Ctrl+C...
An alarm is set for 5 seconds to terminate the process.
^C^C
Time limit reached. Exiting cleanly...
```
