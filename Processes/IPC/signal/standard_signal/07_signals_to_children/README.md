# Signals to Multiple Children
A C program demonstrating inter-process signaling between a parent process and multiple child processes using distinct user signals (`SIGUSR1` and `SIGUSR2`).
## Description
This program demonstrates parent-child synchronization via signals. The parent forks two child processes:
1. The first child sets a signal handler for `SIGUSR1` and suspends execution using `pause()`.
2. The second child sets a signal handler for `SIGUSR2` and suspends execution using `pause()`.

The parent process sleeps briefly to ensure both children are prepared, then dispatches `SIGUSR1` to the first child and `SIGUSR2` to the second child using `kill()`. Each child catches its designated signal, reports execution, and exits cleanly. The parent reaps both children with `wait()`.
## Features
- Creation and management of multiple child processes via `fork()`.
- Distinct signal handlers (`SIGUSR1` for Child 1, `SIGUSR2` for Child 2).
- Execution suspension via `pause()` awaiting signal arrival.
- Targeted signal dispatching using `kill()`.
- Process synchronization and cleanup with `wait()`.
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
./signals_to_children
```
## Usage Examples
**Signals to Children Output Example:**
```text


Signals to Multiple Children


[PARENT] -> Sending SIGUSR1 to first child...
[PARENT] -> Sending SIGUSR2 to second child...
[FIRST CHILD] -> I got SIGUSR1 signal!
[SECOND CHILD] -> I got SIGUSR2 signal!

[PARENT] -> Both children finished work.
```
