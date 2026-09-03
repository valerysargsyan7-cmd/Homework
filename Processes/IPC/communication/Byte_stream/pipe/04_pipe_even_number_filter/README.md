# Unnamed Pipe IPC: Integer Dataset Stream & Filter
A C program demonstrating producer-consumer stream processing using a pipe where a parent process produces an integer sequence and a worker child process consumes the stream and filters even values.
## Description
This program demonstrates the Unix stream filtering paradigm:
1. `pipe()` establishes the binary IPC stream.
2. The producer (parent) populates a 10-element integer dataset $\{1, 2, \dots, 10\}$ and writes the buffer to the pipe.
3. The consumer (child) receives the raw binary integers into its input buffer.
4. The consumer applies a modulo-2 filter (`arr[i] % 2 == 0`) and emits only the matching even values.
5. The parent awaits consumer termination via `wait()`.
## Features
- Producer-consumer architecture across process boundaries.
- Binary stream filtering.
- Automatic resource cleanup.
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
./pipe_even_number_filter
```
## Usage Examples
**Pipe Even Number Filter Output Example:**
```text


Unnamed Pipe IPC: Integer Dataset Stream & Filter

[PARENT] -> Transmitting dataset {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} via pipe...
[CHILD FILTER] -> Received 10 integers from stream.
[CHILD FILTER] -> Filtering and printing even numbers: 2 4 6 8 10 
[PARENT] -> Child stream filtering finished.
```
