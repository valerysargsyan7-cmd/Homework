# Dynamic Binary IPC Reader with Geometric Realloc
A modular C library project demonstrating streaming binary file deserialization using geometrically expanding dynamic heap buffers (`realloc()`) across process boundaries.
## Description
This project demonstrates dynamic stream reading of unknown-length binary datasets:
1. **IPC Buffer Library (`ipc_buffer.h` / `ipc_buffer.c`)**:
   - `read_dynamic_numbers(const char *file, int *out_count)` begins with an initial allocation of 5 integer elements.
   - Reads 32-bit integer records one-by-one with `fread()`.
   - When capacity is reached, doubles the heap buffer size (`capacity *= 2`) with `realloc()`, minimizing reallocation overhead.
   - Returns the dynamic array and writes the total element count into `out_count`.
2. **Driver (`main.c`)**: Parent writes a binary dataset of integers, child process reads and parses it dynamically, and parent cleans up.
## Project Structure
```text
34_dynamic_binary_ipc_reader/
├── ipc_buffer.c
├── ipc_buffer.h
├── main.c
├── Makefile
└── README.md
```
## Features
- Geometric buffer expansion strategy (\(O(1)\) amortized reallocation).
- Binary record deserialization via `fread()`.
- Clean error checking on reallocation.
- Parent-child synchronization with `wait()`.
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
To clean up built binaries and created binary test files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./dynamic_binary_ipc_reader
```
## Usage Examples
**Dynamic Binary IPC Reader Output Example:**
```text


Dynamic Binary IPC Reader with Geometric Realloc

[PARENT] -> Wrote 12 integers to 'rand_numbers.bin'.

[CHILD] -> Read 12 elements dynamically:
  Element[0] = 10
  Element[1] = 20
  Element[2] = 30
  Element[3] = 40
  Element[4] = 50
  Element[5] = 60
  Element[6] = 70
  Element[7] = 80
  Element[8] = 90
  Element[9] = 100
  Element[10] = 110
  Element[11] = 120

[PARENT] -> Child read finished. Exiting.
```
