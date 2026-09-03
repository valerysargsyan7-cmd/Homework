# Grandchild Process Group
A C program demonstrating a 3-tier process hierarchy (parent, child, grandchild) and custom process group ID (PGID) separation using `setpgid()`.
## Description
This program demonstrates process genealogy and process group isolation. The execution flow is:
1. The parent process prints its PID and PGID, then forks a child process.
2. The child process inherits the parent's PGID, prints its PID and PGID, and forks a grandchild process.
3. The grandchild breaks away from the inherited process group by calling `setpgid(0, 0)`, creating a new process group with its own PID as the PGID leader, and prints the updated IDs.
4. Each parent level waits for its descendant with `wait()`.
## Features
- Multi-tier process hierarchy (`parent -> child -> grandchild`).
- Retrieval of process and group IDs using `getpid()` and `getpgid()`.
- Process group separation and new group creation via `setpgid(0, 0)`.
- Hierarchical process synchronization with `wait()`.
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
./grandchild_process_group
```
## Usage Examples
**Grandchild Process Group Output Example:**
```text


Process Hierarchy & Grandchild Process Group

[PARENT] -> PID: 21040, PGID: 21040

[CHILD] -> PID: 21041, PGID: 21040
[GRANDCHILD] -> PID: 21042, PGID: 21042
[CHILD] -> Grandchild finished.

[PARENT] -> Child finished.
```
