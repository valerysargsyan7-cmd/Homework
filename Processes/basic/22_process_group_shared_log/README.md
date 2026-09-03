# Process Group Shared File Logging
A C program demonstrating multi-child process group formation via `setpgid()` with concurrent atomic logging to a shared file in `O_APPEND` mode.
## Description
This program demonstrates coordinating process groups with file I/O:
1. The parent creates three child processes (Child 2, Child 3, Child 4).
2. Each child opens `group_log.txt` in append mode (`O_APPEND`) and writes a formatted PID status string before exiting.
3. The parent binds all three children into a unified process group (`PGID = child_2`) using `setpgid()`.
4. The parent synchronizes and reaps all 3 child processes with `wait()`, then outputs the compiled log file content.
## Features
- Multiple child process generation via `fork()`.
- Process group affiliation with `setpgid()`.
- Multi-process atomic file appending using `O_APPEND`.
- Synchronized parent cleanup and log verification.
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
./process_group_shared_log
```
## Usage Examples
**Process Group Shared Log Output Example:**
```text


Process Group Shared File Logging

[PARENT] -> Group generation (PGID: 29501)...
[PARENT] -> First child status: DONE
[PARENT] -> Second child status: DONE
[PARENT] -> Third child status: DONE

--- Group Log Content (group_log.txt) ---
[CHILD_2] -> worked (PID: 29501)
[CHILD_3] -> worked (PID: 29502)
[CHILD_4] -> worked (PID: 29503)
```
