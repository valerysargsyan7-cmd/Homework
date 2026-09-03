# Parallel Matrix Row Multiplier (3 Processes)
A C program demonstrating map-reduce multi-processing where three child processes in a common process group compute scalar row transformations on a binary 3x3 matrix in parallel, and the parent assembles the resulting dynamic 2D matrix.
## Description
This program demonstrates distributed matrix computation across processes:
1. The parent creates and writes a 3x3 binary matrix into `matrix.bin`.
2. Three worker child processes are launched and bound into a single process group using `setpgid()`:
   - **Child 4 (Row 1)**: Reads row 1 from offset 0, multiplies each element by 2, and writes to `row1.bin`.
   - **Child 5 (Row 2)**: Seeks to offset `3 * sizeof(int)`, multiplies row 2 by 2, and writes to `row2.bin`.
   - **Child 6 (Row 3)**: Seeks to offset `6 * sizeof(int)`, multiplies row 3 by 2, and writes to `row3.bin`.
3. The parent waits for all workers to complete, dynamically allocates a 2D matrix (`int **parent_matrix`), loads the transformed rows, displays the final multiplied matrix, and frees all memory.
## Features
- Multi-process parallel matrix partitioning.
- Dynamic 2D matrix memory management (`int **`) with row allocation.
- Process group affiliation with `setpgid()`.
- File-based intermediate result aggregation.
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
To clean up built binaries and generated partition files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./parallel_matrix_row_multiplier
```
## Usage Examples
**Parallel Matrix Multiplier Output Example:**
```text


Parallel Matrix Row Multiplier (3 Processes)

[PARENT] -> Created 3x3 matrix in 'matrix.bin'.
[CHILD 4] -> Row 1 multiplied by 2 and written to 'row1.bin'.
[CHILD 5] -> Row 2 multiplied by 2 and written to 'row2.bin'.
[CHILD 6] -> Row 3 multiplied by 2 and written to 'row3.bin'.

[PARENT] -> All 3 worker children finished. Assembling dynamic 2D matrix...

---- TRANSFORMED 3x3 MATRIX (Values * 2) ----

   2    4    6 
   8   10   12 
  14   16   18 

[PARENT] -> Pipeline complete.
```
