# Dynamic Two Sum (Heap-Allocated Result)
A C program demonstrating function return of dynamically allocated heap arrays implementing the classic Two-Sum algorithm.
## Description
This program demonstrates the dynamic return pattern in C:
1. `two_sum()` accepts an input array, length, and a target sum integer.
2. It iterates through all pairs of elements using brute-force nested loops.
3. Upon finding a pair whose sum equals `target`, it allocates a 2-element heap buffer (`int *sum_index = malloc(2 * sizeof(int))`), populates it with the pair's indices, and returns the pointer to the caller.
4. If no pair matches, it returns `NULL`.
5. The calling `main()` function checks for `NULL`, displays the result, and takes responsibility for calling `free()` on the returned heap block.
## Features
- Dynamic heap buffer return across function boundaries.
- Classic Two-Sum index resolution.
- Dynamic input array allocation and randomized generation.
- Caller-side memory ownership and `free()` deallocation.
- Standard C17 compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
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
./dynamic_two_sum
```
## Usage Examples
**Dynamic Two Sum Output Example:**
```text


Dynamic Two Sum (Heap-Allocated Result)

Enter elements quantity: 5

Array elements: 12 45 7 28 33 
Enter target sum: 40

[SUCCESS] Pair found at indices: [2, 4]
Values: nums[2] (7) + nums[4] (33) = 40

Memory deallocated successfully.
```
