# Unnamed Pipe IPC: Uppercase Text Stream Converter
A C program demonstrating text streaming and filtering through an unnamed pipe where a lowercase text message is transformed into uppercase across process boundaries.
## Description
This program demonstrates stream string transformation across processes:
1. `pipe()` initializes the communication channels.
2. The parent writes a null-terminated string `"game over"` into the pipe write-end and closes it.
3. The child reads the character stream from the pipe read-end into its local buffer.
4. The child iterates over the buffer, calling `toupper()` on every character, and prints the capitalized result.
5. The parent awaits child completion via `wait()`.
## Features
- Stream-based text IPC using POSIX pipes.
- In-place string casing transformation (`toupper`).
- Proper file descriptor lifecycle management.
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
./pipe_uppercase_converter
```
## Usage Examples
**Pipe Uppercase Converter Output Example:**
```text


Unnamed Pipe IPC: Uppercase Text Stream Converter

[PARENT] -> Sending message: "game over" through pipe...
[CHILD]  -> Converted to UPPERCASE: "GAME OVER"
[PARENT] -> Processing completed.
```
