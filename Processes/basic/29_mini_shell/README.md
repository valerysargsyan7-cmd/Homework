# Mini Shell
An interactive modular Unix command-line shell featuring dynamic argument tokenization with `realloc()` and external process execution via `fork()` and `execvp()`.
## Description
This project implements a lightweight interactive Unix shell (REPL) structured across modular components:
1. **REPL Frontend (`main.c`)**: Renders the `mini_shell>` prompt, captures user command lines using `fgets()`, strips newlines, and handles built-in commands (e.g. `exit`).
2. **Tokenizer Module (`parser.c` / `parser.h`)**: Dynamically parses input lines by whitespace delimiters, expanding its token array using `realloc()` as needed, and returns a `NULL`-terminated argument array.
3. **Execution Engine (`executor.c` / `executor.h`)**: Spawns a child process using `fork()`, executes commands via `execvp()`, and ensures parent synchronization with `wait()`.
## Project Structure
```text
29_mini_shell/
├── executor.c
├── executor.h
├── main.c
├── Makefile
├── parser.c
├── parser.h
└── README.md
```
## Features
- Interactive Read-Eval-Print Loop (REPL).
- Dynamic argument vector allocation and reallocation.
- Modular architecture with clear header/source separation.
- Built-in `exit` command handling.
- System program execution with standard `PATH` lookup via `execvp()`.
- Standard C17 and POSIX compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS)
## Building
To compile the shell, run:
```bash
make
```
To clean up built binaries and object files:
```bash
make clean
```
## Running
Run the compiled shell executable:
```bash
./mini_shell
```
## Usage Examples
**Mini Shell Session Example:**
```text
==============================
||        MINI SHELL        ||
==============================

mini_shell> echo Hello World from Mini Shell!
Hello World from Mini Shell!
mini_shell> uname -s
Linux
mini_shell> pwd
/home/davit/Desktop/C/Processes/basic/29_mini_shell
mini_shell> exit

Goodbye from mini_shell!
```
