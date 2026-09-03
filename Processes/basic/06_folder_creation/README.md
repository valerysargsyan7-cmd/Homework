# Folder Creation
A C program demonstrating external system command execution via `execlp()` inside a child process to create a directory.
## Description
This program demonstrates executing an external utility (`mkdir`) within a child process using `execlp()`. The child executes `mkdir -p NewHomework` to create a directory. If the executable fails to launch, the child reports the error via `perror()`. The parent waits for child termination and inspects the exit status with `WIFEXITED()` and `WEXITSTATUS()` to verify successful creation.
## Features
- Child process creation with `fork()`.
- System utility execution (`mkdir`) using `execlp()`.
- Exit status verification using `WIFEXITED` and `WEXITSTATUS`.
- Standard C17 and POSIX compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system with `mkdir` available on `PATH`
## Building
To compile the project, run:
```bash
make
```
To clean up built binaries and created test directories:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./folder_creation
```
## Usage Examples
**Folder Creation Output Example:**
```text


Folder Creation


[PARENT] -> Folder created successfully!
```
