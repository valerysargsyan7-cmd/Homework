# Process Group Signal Broadcast & Migration
A C program demonstrating group signal broadcasting with `killpg()` and dynamic runtime process group migration using `setpgid()`.
## Description
This program demonstrates dynamic group signal routing. The parent forks Child 5 and Child 6 and places both in a process group (`PGID = child_5`). The sequence proceeds as follows:
1. **1st Broadcast**: The parent issues `killpg(child_5, SIGUSR1)`. Both Child 5 and Child 6 receive the signal.
2. **Dynamic Migration**: In response to the signal, Child 5 calls `setpgid(0, parent_pgid)`, leaving the group and joining the parent's group. Child 6 remains in `child_5`'s group.
3. **2nd Broadcast**: The parent issues `killpg(child_5, SIGUSR1)` again. Only Child 6 receives the second signal since Child 5 has migrated away.
4. The parent reaps both children.
## Features
- Process group initialization with `setpgid()`.
- Group-wide signal broadcasting via `killpg()`.
- Dynamic runtime group reassignment from within a signal handler.
- Verification of selective signal delivery after group migration.
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
./group_signal_migration
```
## Usage Examples
**Group Signal Migration Output Example:**
```text


Process Group Signal Broadcast & Migration

[CHILD 5] -> Born (PID: 24501)
[CHILD 6] -> Born (PID: 24502)

[PARENT] -> Broadcasting 1st SIGUSR1 to Process Group 24501 via killpg()...
[CHILD 5] -> Handled SIGUSR1 (migrated back to parent PGID 24500)!
[CHILD 6] -> Handled SIGUSR1 (remains in PGID 24501)!

[PARENT] -> Broadcasting 2nd SIGUSR1 to Process Group 24501 (only Child 6 remains)...
[CHILD 6] -> Handled SIGUSR1 (remains in PGID 24501)!

[PARENT] -> Cleaning up children with SIGKILL...
[PARENT] -> Both children finished.
```
