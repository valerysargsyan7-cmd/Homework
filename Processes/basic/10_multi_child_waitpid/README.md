# Multi-Child Targeted Waitpid
A C program demonstrating non-blocking concurrent child process execution and ordered child termination synchronization using `waitpid()`.
## Description
This program spawns three separate child processes running with different sleep durations:
- Child 1: 5 seconds
- Child 2: 3 seconds
- Child 3: 1 second

The parent tracks all three child PIDs in an array and synchronizes with their termination in an explicit sequence (Child 3 first, then Child 2, then Child 1) using `waitpid()`, demonstrating that processes can be reaped in any specified order.
## Features
- Concurrent creation of three child processes via `fork()`.
- PID array storage for multi-process tracking.
- Ordered child process synchronization using `waitpid()`.
- Clean termination and zombie prevention.
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
./multi_child_waitpid
```
## Usage Examples
**Multi-Child Waitpid Output Example:**
```text


Multi-Child Targeted Waitpid

[CHILD 1] -> Sleeping for 5 seconds...
[CHILD 2] -> Sleeping for 3 seconds...
[CHILD 3] -> Sleeping for 1 second...

[PARENT] -> Waiting for Child 3 (PID: 19102)...
[CHILD 3] -> Finished.
[PARENT] -> Process with 19102 PID reaped.

[PARENT] -> Waiting for Child 2 (PID: 19101)...
[CHILD 2] -> Finished.
[PARENT] -> Process with 19101 PID reaped.

[PARENT] -> Waiting for Child 1 (PID: 19100)...
[CHILD 1] -> Finished.
[PARENT] -> Process with 19100 PID reaped.

All 3 child processes finished.
```
