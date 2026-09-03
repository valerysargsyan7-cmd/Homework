# Inter-Process Shared Struct Turn Synchronization
A C program demonstrating lockstep inter-process state synchronization across parent and child processes using an anonymous shared memory struct (`struct State`) with turn-taking flags.
## Description
This program demonstrates coordinating alternating execution across process boundaries without semaphores:
1. `mmap_obj()` allocates a `struct State` (`volatile int turn`, `volatile int value`) using `mmap(MAP_SHARED | MAP_ANONYMOUS)`.
2. Initial state is set to `turn = 0`, `value = 1`.
3. The parent and child loop 5 times in lockstep:
   - **Child**: Waits for `turn == 0`, multiplies `value` by 2, prints progress, and sets `turn = 1`.
   - **Parent**: Waits for `turn == 1`, multiplies `value` by 3, prints progress, and sets `turn = 0`.
4. Over 5 rounds, the value is progressively multiplied by \(2 \times 3 = 6\) each round (\(1 \to 6 \to 36 \to 216 \to 1296 \to 7776\)).
5. The parent reaps the child and unmaps the shared struct.
## Features
- Strict turn-taking synchronization via shared atomic fields.
- Anonymous shared struct memory mapping (`mmap`).
- Volatile fields preventing compiler register caching across process boundaries.
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
./struct_synchronization_turn
```
## Usage Examples
**Struct Synchronization Output Example:**
```text


Inter-Process Shared Struct Turn Synchronization

Initial State: turn = 0, value = 1

[CHILD  (Step 1/5)] -> value (* 2) = 2
[PARENT (Step 1/5)] -> value (* 3) = 6
[CHILD  (Step 2/5)] -> value (* 2) = 12
[PARENT (Step 2/5)] -> value (* 3) = 36
[CHILD  (Step 3/5)] -> value (* 2) = 72
[PARENT (Step 3/5)] -> value (* 3) = 216
[CHILD  (Step 4/5)] -> value (* 2) = 432
[PARENT (Step 4/5)] -> value (* 3) = 1296
[CHILD  (Step 5/5)] -> value (* 2) = 2592
[PARENT (Step 5/5)] -> value (* 3) = 7776

Final Shared State value = 7776
Shared struct unmapped cleanly.
```
