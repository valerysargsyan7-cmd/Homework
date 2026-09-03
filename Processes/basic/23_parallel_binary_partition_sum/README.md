# Parallel Binary Partition Summing
A C program demonstrating map-reduce style parallel array processing where two child processes compute sums of non-overlapping binary file partitions using `fseek()` and `fread()`.
## Description
This program demonstrates concurrent binary data division across processes:
1. The parent creates and initializes a binary file (`data.bin`) with 100 consecutive 32-bit integers (`1..100`).
2. **Child 5 (Partition 1)**: Reads the first 50 integers starting from offset 0, computes the partial sum (\(1 + 2 + \dots + 50 = 1275\)), and outputs the result.
3. **Child 6 (Partition 2)**: Seeks to offset `50 * sizeof(int)` using `fseek()`, reads the subsequent 50 integers (`51..100`), computes the partial sum (\(51 + 52 + \dots + 100 = 3775\)), and outputs the result.
4. The parent reaps both children and summarizes the aggregate results (\(1275 + 3775 = 5050\)).
## Features
- Direct binary dataset initialization via `fwrite()`.
- Offset-targeted stream positioning with `fseek()`.
- Parallel chunk calculation across multiple spawned processes.
- Parent synchronization and exit code collection with `wait()`.
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
To clean up built binaries and generated binary data files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./parallel_binary_partition_sum
```
## Usage Examples
**Parallel Partition Summing Output Example:**
```text


Parallel Binary Partition Summing

[PARENT] -> Initialized 'data.bin' with 100 integers (1..100).

[CHILD 5] -> Sum of first partition (1..50): 1275
[CHILD 6] -> Sum of second partition (51..100): 3775

[PARENT] -> Both children finished processing partitions.
[PARENT] -> Expected total sum (1..100) = 5050 (1275 + 3775).
```
