# Zombie Hunter (killpg & Non-Blocking Reaping)
A modular C library project demonstrating group-wide process termination via `killpg(SIGKILL)` combined with non-blocking kernel table zombie reaping using `waitpid(WNOHANG)`.
## Description
This project demonstrates clearing terminated child processes from the operating system table:
1. **Zombie Hunter Library (`zombie_hunter.h` / `zombie_hunter.c`)**:
   - `hunt_zombies(pid_t pgid)` sends `SIGKILL` to an entire process group (`killpg(pgid, SIGKILL)`).
   - Loops using non-blocking status polling (`waitpid(-1, &status, WNOHANG)`), reaping every terminated process and reporting its PID until no zombie remains in the kernel table.
2. **Driver (`main.c`)**: Spawns 5 child processes, groups them under `pids[0]` using `setpgid()`, and triggers `hunt_zombies()`.
## Project Structure
```text
22_zombie_hunter_killpg/
├── main.c
├── Makefile
├── README.md
├── zombie_hunter.c
└── zombie_hunter.h
```
## Features
- Process group management with `setpgid()`.
- Group-wide termination using `killpg()`.
- Non-blocking zombie reclamation via `waitpid(-1, &status, WNOHANG)`.
- Prevention of kernel process table exhaustion.
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
./zombie_hunter
```
## Usage Examples
**Zombie Hunter Output Example:**
```text


Zombie Hunter (killpg & Non-Blocking Reaping)

[PARENT] -> 5 worker processes spawned into Process Group 36101.
[PARENT] -> Initiating zombie hunt and reap cycle...

[HUNTER] -> Issuing killpg(PGID: 36101, SIGKILL)...
[HUNTER] -> Process 36101 reaped from kernel process table (status: 9).
[HUNTER] -> Process 36102 reaped from kernel process table (status: 9).
[HUNTER] -> Process 36103 reaped from kernel process table (status: 9).
[HUNTER] -> Process 36104 reaped from kernel process table (status: 9).
[HUNTER] -> Process 36105 reaped from kernel process table (status: 9).

[PARENT] -> All zombie processes reaped successfully.
```
