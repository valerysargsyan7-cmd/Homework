# Modular Parallel Chunk Summing (Map-Reduce)
A modular C library project providing multi-process Map-Reduce array summation across configurable child process chunks using temporary file IPC.
## Description
This project demonstrates parallel map-reduce processing:
1. **Parallel Math Library (`parallel_math.h` / `parallel_math.c`)**:
   - `parallel_sum(const int *arr, int size, int chunks)` divides an input array into \(N\) contiguous partitions.
   - Forks \(N\) worker child processes simultaneously.
   - Each worker sums its assigned sub-array and writes the partial sum to a temporary IPC file (`tmp_chunk_X.txt`).
   - The parent synchronizes all child processes using `waitpid()`.
   - The parent reads all partial sums, computes the aggregate total, unlinks temporary files, and returns the result.
2. **Driver (`main.c`)**: Initializes a sample array, invokes `parallel_sum()`, and verifies the total sum.
## Project Structure
```text
32_modular_parallel_sum/
├── main.c
├── Makefile
├── parallel_math.c
├── parallel_math.h
└── README.md
```
## Features
- Scalable array partitioning across \(N\) child processes.
- IPC file aggregation and automatic cleanup via `unlink()`.
- Clean modular interface separating mathematical engine from caller.
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
To clean up built binaries and temporary chunk files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./modular_parallel_sum
```
## Usage Examples
**Modular Parallel Sum Output Example:**
```text


Modular Parallel Chunk Summing (Map-Reduce)

Summing array of 20 elements (1..20) across 4 worker processes:

[CHILD 0] -> Calculated chunk sum (0..4): 15
[CHILD 1] -> Calculated chunk sum (5..9): 40
[CHILD 2] -> Calculated chunk sum (10..14): 65
[CHILD 3] -> Calculated chunk sum (15..19): 90

[PARENT] -> Combined Total Sum: 210 (Expected: 210)
```
