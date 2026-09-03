# Signal-Synchronized String Reversal Pipeline
A C program demonstrating an inter-process text transformation pipeline where a parent populates input strings and signals the waiting child via `SIGUSR1` to perform in-place string reversals.
## Description
This program demonstrates file processing triggered by asynchronous POSIX signals:
1. The parent writes a list of words (`"Apple"`, `"Banana"`, `"Cherry"`) to `words.txt`.
2. The child registers a handler for `SIGUSR1` and enters a paused state (`pause()`).
3. The parent sends `SIGUSR1` to the child via `kill()`.
4. Upon waking, the child reads each word from `words.txt`, dynamically allocates a string buffer, applies in-place two-pointer string reversal (`reversing_string()`), and writes the reversed results into `reversed.txt`.
5. The parent waits for child termination and displays the reversed output file.
## Features
- Signal-triggered processing using `SIGUSR1`.
- Safe atomic signal flag handling with `volatile sig_atomic_t`.
- In-place two-pointer string reversal algorithm.
- Intermediate file pipeline output (`words.txt` -> `reversed.txt`).
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
To clean up built binaries and created text files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./signal_string_reversal
```
## Usage Examples
**Signal String Reversal Output Example:**
```text


Signal-Synchronized String Reversal Pipeline

[CHILD] -> Waiting for SIGUSR1 signal from PARENT...
[PARENT] -> Words written to 'words.txt'. Sending SIGUSR1 to child (PID: 31201)...
[CHILD] -> Transformed: 'Apple' -> 'elppA'
[CHILD] -> Transformed: 'Banana' -> 'ananaB'
[CHILD] -> Transformed: 'Cherry' -> 'yrrehC'

[CHILD] -> Program Status: DONE (Saved to 'reversed.txt')

--- Reversed File Content (reversed.txt) ---
elppA
ananaB
yrrehC

[PARENT] -> Program complete.
```
