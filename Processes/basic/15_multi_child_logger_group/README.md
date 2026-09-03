# Multi-Child Logger Group
A C program demonstrating multi-process append logging to a shared log file with coordinated process group management via `setpgid()`.
## Description
This program demonstrates coordinating background worker/logger processes. Three child processes are created:
- Child 12, Child 13, and Child 14 each write periodic log messages to a common file (`audit.log`) opened in `O_APPEND` mode.
- The parent groups all three logger children into a single process group (`PGID = child_12`) using `setpgid()`.

The parent waits for all workers to complete their logging loops, closes the file, and reads back the full generated audit log.
## Features
- Multiple child processes writing concurrently to a shared append descriptor.
- Process group consolidation via `setpgid()`.
- Synchronized parent collection and cleanup with `wait()`.
- Full audit file output demonstration upon completion.
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
To clean up built binaries and generated log files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./multi_child_logger_group
```
## Usage Examples
**Multi-Child Logger Group Output Example:**
```text


Multi-Child Logger Group

[PARENT] -> Loggers started in process group 26101.

[PARENT] -> All logger children finished.

--- Audit Log Content (audit.log) ---
[1_CHILD] -> Running...
[2_CHILD] -> Running...
[3_CHILD] -> Running...
[1_CHILD] -> Running...
[2_CHILD] -> Running...
[3_CHILD] -> Running...
[1_CHILD] -> Running...
[2_CHILD] -> Running...
[3_CHILD] -> Running...
```
