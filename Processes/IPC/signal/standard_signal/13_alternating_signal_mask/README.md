# Alternating Signal Mask (Safe vs Dangerous Zones)
A C program demonstrating runtime toggling of signal masks via `sigprocmask()` to create alternating critical (safe) sections and non-critical (dangerous) sections.
## Description
This program demonstrates dynamic signal management in a loop. It alternates between two distinct phases:
1. **Safe Zone**: `sigprocmask(SIG_BLOCK, &set, NULL)` is invoked to block `SIGINT`. During this 2-second sleep window, any Ctrl+C signals sent to the process remain pending and cannot interrupt execution.
2. **Dangerous Zone**: `sigprocmask(SIG_UNBLOCK, &set, NULL)` is invoked to restore default delivery of `SIGINT`. Any pending signals from the safe zone are immediately delivered, and new Ctrl+C inputs will terminate the process.
## Features
- Dynamic signal set configuration with `sigemptyset()` and `sigaddset()`.
- Critical section protection via `sigprocmask(SIG_BLOCK)`.
- Re-enabling signal reception via `sigprocmask(SIG_UNBLOCK)`.
- Demonstration of pending signal delivery upon unmasking.
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
./alternating_signal_mask
```
## Usage Examples
**Alternating Signal Mask Output Example:**
```text


Alternating Signal Mask (Safe vs Dangerous Zones)


[Iteration 1/5] Entered Safe Zone (Ctrl+C turned OFF)...
[Iteration 1/5] Entered Dangerous Zone (Ctrl+C turned ON)...

[Iteration 2/5] Entered Safe Zone (Ctrl+C turned OFF)...
[Iteration 2/5] Entered Dangerous Zone (Ctrl+C turned ON)...

Completed all 5 iterations successfully.
```
