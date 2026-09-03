# Signal-Driven Remote Memory Lifecycle Manager
A C program demonstrating remote runtime memory allocation and deallocation across process boundaries using asynchronous POSIX signals (`SIGUSR1`, `SIGUSR2`, `SIGTERM`).
## Description
This program demonstrates controlling the dynamic memory lifecycle of a background worker process via IPC signals:
1. The child process registers signal handlers for:
   - `SIGUSR1`: Requests dynamic memory allocation (`malloc()`).
   - `SIGUSR2`: Requests dynamic memory deallocation (`free()`).
   - `SIGTERM`: Requests graceful termination.
2. Signal handlers set atomic flags (`volatile sig_atomic_t`), leaving memory management calls to the main event loop to preserve async-signal safety.
3. The parent process drives 3 full cycles of alternating `SIGUSR1` and `SIGUSR2` signals.
4. Finally, the parent sends `SIGTERM`, and the child deallocates any remaining heap memory before exiting cleanly.
## Features
- Signal-controlled heap memory allocation and freeing.
- Safe asynchronous signal handling with `volatile sig_atomic_t`.
- Double-allocation and double-free guard protections.
- Graceful shutdown upon `SIGTERM`.
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
./signal_memory_manager
```
## Usage Examples
**Signal Memory Manager Output Example:**
```text


Signal-Driven Remote Memory Lifecycle Manager

[CHILD] -> Ready. Waiting for signal memory commands...

--- Cycle 1 ---
[PARENT] -> Sending SIGUSR1 (Allocate)...
[CHILD] -> [SIGUSR1] 1000 ints allocated on heap (Addr: 0x55d7f1d432a0)
[PARENT] -> Sending SIGUSR2 (Free)...
[CHILD] -> [SIGUSR2] Dynamic memory freed safely.

--- Cycle 2 ---
[PARENT] -> Sending SIGUSR1 (Allocate)...
[CHILD] -> [SIGUSR1] 1000 ints allocated on heap (Addr: 0x55d7f1d432a0)
[PARENT] -> Sending SIGUSR2 (Free)...
[CHILD] -> [SIGUSR2] Dynamic memory freed safely.

--- Cycle 3 ---
[PARENT] -> Sending SIGUSR1 (Allocate)...
[CHILD] -> [SIGUSR1] 1000 ints allocated on heap (Addr: 0x55d7f1d432a0)
[PARENT] -> Sending SIGUSR2 (Free)...
[CHILD] -> [SIGUSR2] Dynamic memory freed safely.

[PARENT] -> Sending SIGTERM to stop child...
[CHILD] -> [SIGTERM] Terminating cleanly.
[PARENT] -> Child terminated cleanly. Program complete.
```
