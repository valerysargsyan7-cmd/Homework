# Three-Stage Pipe Command Pipeline: cat data.txt | grep A | sort
A C program implementing a 3-stage Unix command pipeline (`cat data.txt | grep A | sort`) using dual POSIX pipes (`pipe()`) and file descriptor duplication (`dup2()`).
## Description
This program demonstrates chaining multiple independent programs through a pipeline:
1. Prepares `data.txt` with sample text lines.
2. Allocates two pipes:
   - `fds_1`: Channeled from `cat` to `grep`.
   - `fds_2`: Channeled from `grep` to `sort`.
3. **Child 1 (`cat data.txt`)**: Redirects stdout to `fds_1[1]`, closes all other pipe descriptors, and executes `cat data.txt`.
4. **Child 2 (`grep A`)**: Redirects stdin from `fds_1[0]` and stdout to `fds_2[1]`, closes all other descriptors, and executes `grep A`.
5. **Child 3 (`sort`)**: Redirects stdin from `fds_2[0]` and outputs sorted lines to standard terminal stdout, executing `sort`.
6. **Parent**: Closes all 4 pipe descriptors to propagate `EOF` across the pipeline and reaps all 3 children using `waitpid()`.
7. Enforces rigorous error handling on every file operation, pipe creation, duplication, and execution step.
## Features
- Full 3-stage command pipeline implementation (`cmd1 | cmd2 | cmd3`).
- Deadlock-free pipe descriptor lifecycle management.
- Multi-process synchronization with `waitpid()`.
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
To clean up built binaries and sample files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./pipe_multi_stage_cat_grep_sort
```
## Usage Examples
**Three-Stage Pipe Output Example:**
```text
Apple
Apricot
Avocado
```
*(Outputs all matching lines filtered for 'A' and alphabetically sorted by `sort`)*
