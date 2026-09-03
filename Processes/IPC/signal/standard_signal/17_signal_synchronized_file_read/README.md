# Signal-Synchronized File Read (SIGUSR1)
A C program demonstrating inter-process coordination where a parent writes a file and notifies the waiting child to consume it using a `SIGUSR1` signal.
## Description
This program demonstrates coordinating file I/O dependencies across processes using signals:
1. The child process registers a handler for `SIGUSR1` and enters low-power suspension with `pause()`, waiting for the parent to signal that data is ready.
2. The parent process writes lines to `Parent.txt`, flushes buffers, and closes the stream.
3. The parent sends `SIGUSR1` to the child via `kill()`.
4. The child wakes up, opens `Parent.txt` in read-only mode, processes and displays the contents, and terminates cleanly.
## Features
- Signal-based inter-process notification using `SIGUSR1`.
- Safe signal flag capture with `volatile sig_atomic_t`.
- Prevention of file read-before-write race conditions.
- Parent-child synchronization and reaping via `wait()`.
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
To clean up built binaries and created test files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./signal_synchronized_file_read
```
## Usage Examples
**Signal-Synchronized File Read Output Example:**
```text


Signal-Synchronized File Read (SIGUSR1)

[CHILD] -> Waiting for parent to finish writing (SIGUSR1)...
[PARENT] -> Writing lines to 'Parent.txt'...
[PARENT] -> File ready. Sleeping for 2 seconds before notifying child...
[PARENT] -> Sending [DONE] SIGUSR1 signal to child (PID: 28401)...
[CHILD] -> Signal received! Opening 'Parent.txt'...

Hello I am line 1
Hello I am line 2
Hello I am line 3

[CHILD] -> Process status: DONE
[PARENT] -> Child finished. Program ending.
```
