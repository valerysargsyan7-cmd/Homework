# External Worker Runner
A modular C project demonstrating parent-child process decoupling and external program execution using `fork()` and `execlp()` with argument forwarding.
## Description
This project demonstrates spawning standalone binary workloads:
1. **Runner Module (`runner.c` / `runner.h`)**: Provides `run_worker_bg(const char *arg)`, which calls `fork()` and uses `execlp("./worker", "./worker", arg, NULL)` to replace the child process image with the compiled `worker` executable.
2. **Worker Target (`worker.c`)**: Standalone program that receives arguments through `argv` and processes its payload.
3. **Driver (`main.c`)**: Coordinates compilation, spawns the worker with custom payload arguments, and reaps the child using `wait()`.
## Project Structure
```text
30_external_worker_runner/
├── main.c
├── Makefile
├── README.md
├── runner.c
├── runner.h
└── worker.c
```
## Features
- Dynamic external binary dispatch via `execlp()`.
- Clean modular isolation between caller and execution engine.
- Argument passing across process replacement boundaries.
- Makefile building multiple target binaries automatically.
- Standard C17 and POSIX compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS)
## Building
To compile the runner and worker binaries, run:
```bash
make
```
To clean up built binaries and object files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./external_runner
```
## Usage Examples
**External Runner Output Example:**
```text


External Worker Runner

[PARENT] -> Launching background worker process...
[WORKER] -> Received Argument: "Task_Payload_Data_123" (PID: 33402)
[PARENT] -> Worker process execution finished.
```
