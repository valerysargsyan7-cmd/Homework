# Child Wait
A C program demonstrating basic process synchronization using `fork()`, `sleep()`, and `wait()`.
## Description
This program demonstrates how a parent process can synchronize with a spawned child process. The parent forks a child process that sleeps for 3 seconds simulating work before exiting. The parent calls `wait(NULL)` to block its own execution until the child terminates, ensuring the child is reaped cleanly before the parent exits.
## Features
- Child process creation with `fork()`.
- Simulated child workload using `sleep()`.
- Blocking parent synchronization and process cleanup using `wait()`.
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
./child_wait
```
## Usage Examples
**Child Wait Output Example:**
```text


Child Wait


[CHILD] -> Loading...

[PARENT] -> CHILD ended, I am ending too...
```
