# Process Group Termination via killpg
A C program demonstrating multi-process group organization using `setpgid()` and simultaneous group termination using `killpg()` with `SIGKILL`.
## Description
This program demonstrates how to structure and control groups of related processes. The parent forks 4 child processes:
- **Child 1 and Child 2**: Grouped together into a dedicated process group (`PGID = child_1`) via `setpgid()`. Both run infinite loops.
- **Child 3 and Child 4**: Remain in the parent's default process group, sleep briefly, and exit normally.

The parent allows Child 3 and 4 to finish, then issues a single `killpg(child_1, SIGKILL)` call to terminate the entire background group (Child 1 & 2) in one operation. The parent reaps all 4 children and verifies their termination status.
## Features
- Forking 4 concurrent child processes.
- Group formation using `setpgid()`.
- Group-wide signal delivery with `killpg()`.
- Distinguishing between normal exits and signal terminations (`WIFSIGNALED`, `WIFEXITED`).
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
./killpg_group_termination
```
## Usage Examples
**Process Group Termination Output Example:**
```text


Process Group Termination via killpg

[CHILD 3] -> Running in parent group (PID: 23112)...
[CHILD 4] -> Running in parent group (PID: 23113)...
[CHILD 3] -> Finished normally.
[CHILD 4] -> Finished normally.

[PARENT] -> Children 1 & 2 assigned to PGID 23110.
[PARENT] -> Sleeping for 3 seconds before killing Group 23110...
[PARENT] -> Sending SIGKILL to Process Group 23110 via killpg()...
[PARENT] -> Child 23112 exited normally with status: 0
[PARENT] -> Child 23113 exited normally with status: 0
[PARENT] -> Child 23110 terminated by signal: 9
[PARENT] -> Child 23111 terminated by signal: 9
[PARENT] -> All 4 children reaped.
```
