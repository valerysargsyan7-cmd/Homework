# Process Task Spawner Framework
A modular C framework implementing higher-order process creation that executes arbitrary function pointers (`void (*task_func)(void)`) inside spawned child processes.
## Description
This project demonstrates creating a reusable process launcher abstraction:
1. **Spawner Library (`proc_utils.h` / `proc_utils.c`)**: Exposes `pid_t spawn_task(void (*task_func)(void))` which encapsulates `fork()`, invokes the passed callback routine in the child context, and returns the newly created PID to the caller.
2. **Driver (`main.c`)**: Passes a concrete task function (`print_working`) to the spawner and awaits execution completion via `waitpid()`.
## Project Structure
```text
33_process_task_spawner/
├── main.c
├── Makefile
├── proc_utils.c
├── proc_utils.h
└── README.md
```
## Features
- Higher-order function callback dispatch across `fork()`.
- Clean encapsulation of process creation boilerplate.
- Parent tracking via PID return values.
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
./process_task_spawner
```
## Usage Examples
**Process Task Spawner Output Example:**
```text


Process Task Spawner Framework

[PARENT] -> Spawned worker child with PID: 34801
[PARENT] -> Waiting for child task with PID: 34801...
  [WORKER] -> Processing batch 1/5...
  [WORKER] -> Processing batch 2/5...
  [WORKER] -> Processing batch 3/5...
  [WORKER] -> Processing batch 4/5...
  [WORKER] -> Processing batch 5/5...

[CHILD] -> Task execution completed. Exiting (PID: 34801)...
[PARENT] -> Child task finished. Exiting.
```
