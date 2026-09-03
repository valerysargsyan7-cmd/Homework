# Unnamed Pipe IPC: Character Stream Length Counter
A C program demonstrating character stream transmission across an unnamed POSIX pipe and manual pointer-based byte counting without external string utilities.
## Description
This program demonstrates stream string transmission:
1. `pipe()` initializes the descriptor pair.
2. The parent transmits a text string (`"Pipes are fun!"`) including the terminating null character into the pipe.
3. The child reads the byte stream from the pipe read descriptor into a local buffer.
4. The child iterates sequentially through the character buffer until `\0` to count the exact number of characters.
5. Displays the received string and computed length.
## Features
- Unidirectional string IPC stream.
- Zero-dependency manual character counter.
- Clean file descriptor management.
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
./pipe_string_length_calculator
```
## Usage Examples
**Pipe String Length Calculator Output Example:**
```text


Unnamed Pipe IPC: Character Stream Length Counter

[PARENT] -> Transmitting text string: "Pipes are fun!" via pipe...
[CHILD]  -> Received stream: "Pipes are fun!"
[CHILD]  -> Computed length: 14 characters
[PARENT] -> Processing concluded.
```
