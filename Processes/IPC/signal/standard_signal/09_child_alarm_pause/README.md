# Child Alarm Pause
A C program demonstrating child process timer scheduling and suspension using `alarm()` and `pause()` with POSIX signal handling.
## Description
This program demonstrates how a spawned child process can independently set a real-time timer using `alarm()`, suspend execution using `pause()`, and wake up upon receipt of `SIGALRM`. The child registers a custom `SIGALRM` signal handler, sets a 2-second alarm, and blocks in `pause()`. Once the signal triggers, the child prints a confirmation message and terminates cleanly. The parent uses `wait()` to synchronize with child termination.
## Features
- Independent child timer scheduling via `alarm(2)`.
- Process suspension waiting for signals using `pause()`.
- Async-signal-safe alarm capture using `volatile sig_atomic_t`.
- Parent-child termination synchronization using `wait()`.
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
./child_alarm_pause
```
## Usage Examples
**Child Alarm Pause Output Example:**
```text


Child Alarm Pause

[CHILD] -> Setting alarm for 2 seconds and pausing...

[HANDLER] -> Alarm in child fired!

[PARENT] -> Parent caught child exit. Done.
```
