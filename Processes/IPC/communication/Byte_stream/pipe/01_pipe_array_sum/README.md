# Unnamed Pipe IPC: Integer Array Summation
A C program demonstrating unidirectional inter-process communication using an unnamed POSIX pipe (`pipe()`) to transmit a raw binary array of integers from a parent process to a child process for summation.
## Description
This program illustrates fundamental stream-oriented inter-process communication:
1. Creates an unnamed pipe file descriptor pair (`fds_1[0]` for read, `fds_1[1]` for write) using `pipe()`.
2. Spawns a child process using `fork()`.
3. The parent closes the unused read descriptor (`fds_1[0]`), writes an array of integers `{1, 2, 3, 4, 5}` via `write()`, and closes the write descriptor (`fds_1[1]`).
4. The child closes the unused write descriptor (`fds_1[1]`), receives the array via `read()`, computes the total sum using `sum_array()`, and outputs the result.
5. The parent reaps the child using `wait()`.
## Features
- Unidirectional IPC byte streaming via `pipe()`.
- Binary struct/array transmission across process boundaries.
- Clean file descriptor lifecycle management.
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
./pipe_array_sum
```
## Usage Examples
**Pipe Array Sum Output Example:**
```text


Unnamed Pipe IPC: Integer Array Summation

[PARENT] -> Sending array {1, 2, 3, 4, 5} through pipe write-end...
[CHILD] -> Received 20 bytes from pipe.
[CHILD] -> Calculated sum: 15
[PARENT] -> Child processing complete. Exiting.
```
