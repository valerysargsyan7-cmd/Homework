# Program Changing
A C program demonstrating the POSIX `execlp()` system call to replace the current process image with another program.
## Description
This program calls `execlp()` to replace itself entirely with the `pwd` command, which then prints the current working directory. If `execlp()` fails (e.g. `pwd` isn't found), it reports the error and exits.
## Features
- Process image replacement via the POSIX `execlp()` system call.
- Error reporting via `perror()` if `execlp()` fails.
- Uses the `PATH` environment variable to locate `pwd` (the `p` in `execlp`), rather than requiring a full path.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS) with a `pwd` executable available on `PATH`
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
./program_changing
```
## Usage Examples
**Program Changing Example:**
```text
/home/user/project
```
Note: the two `printf` lines before `execlp()` don't appear in the output above. That's not a bug — their text was still sitting unflushed in stdout's buffer when `execlp()` ran, and since `execlp()` replaces the process image entirely (unlike `fork()`, which duplicates it), that unflushed buffer is discarded rather than inherited. Only `pwd`'s own output survives. If you want those lines to actually print, you'd need to flush stdout (e.g. `fflush(stdout);`) before the `execlp()` call — not something I changed, just explaining the behavior you'll see when you run it.