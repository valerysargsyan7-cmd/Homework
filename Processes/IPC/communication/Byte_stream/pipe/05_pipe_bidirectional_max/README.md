# Bidirectional Full-Duplex Dual Pipe IPC: Max Computation
A C program demonstrating full-duplex bidirectional inter-process communication using two independent POSIX pipes configured as request and response channels between parent and child processes.
## Description
Because standard Unix unnamed pipes are strictly unidirectional, bidirectional communication requires two distinct pipe pairs:
1. **Request Channel (`fds_1`)**: Transmits raw numbers from the Parent to the Child.
2. **Response Channel (`fds_2`)**: Transmits the computed computation result from the Child back to the Parent.
3. The parent generates two random integers and transmits them through `fds_1`.
4. The child reads the pair from `fds_1`, calculates the maximum value, and returns the maximum integer through `fds_2`.
5. The parent reads the result from `fds_2` and displays the computed maximum.
## Features
- Full-duplex bidirectional IPC using two separate unnamed pipes.
- Deadlock prevention via strict file descriptor closure on unused ends.
- Parent-child request-response protocol.
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
./pipe_bidirectional_max
```
## Usage Examples
**Pipe Bidirectional Max Output Example:**
```text


Bidirectional Full-Duplex Dual Pipe IPC: Max Computation

[PARENT] -> Generated numbers: [384, 892]
[PARENT] -> Sending numbers to child via Pipe 1...
[CHILD]  -> Received two numbers: [384, 892]
[CHILD]  -> Computed maximum: 892. Sending back to parent via Pipe 2...
[PARENT] -> Received Maximum from child via Pipe 2: 892
[PARENT] -> Bidirectional exchange finished.
```
