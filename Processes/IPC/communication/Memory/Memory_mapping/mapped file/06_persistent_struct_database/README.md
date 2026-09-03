# Persistent Struct Database via Mmap
A C program demonstrating the implementation of a zero-overhead persistent record database by mapping a fixed-size `struct User` table directly to disk with `ftruncate()` and `mmap(MAP_SHARED)`.
## Description
This program demonstrates how real-world embedded databases map in-memory data structures directly to disk:
1. `load_database()` creates or opens `user_database.dat`, formats the file to hold exactly \(N\) records of `struct User` via `ftruncate()`, and maps the entire table with `MAP_SHARED`.
2. Any record created in memory (`db[i].id`, `db[i].name`, `db[i].age`) is instantly mirrored on disk by the kernel page cache.
3. Provides an interactive menu to add records, view all active users, and persist on clean exit.
## Features
- Fixed-schema persistent table mapped to disk.
- Zero explicit file serialization loops (`read`/`write`).
- Interactive CLI database operations.
- Clean unmapping and resource release.
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
To clean up built binaries and database files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./persistent_struct_database
```
## Usage Examples
**Persistent Struct Database Output Example:**
```text


Persistent Struct Database via Mmap

--- Database Menu ---
1. Add user record
2. Show all user records
3. Exit
Select option: 1
Enter User ID: 101
Enter Username: Alice
Enter Age: 28
[SUCCESS] User saved at slot 0 directly to mapped file.

--- Database Menu ---
1. Add user record
2. Show all user records
3. Exit
Select option: 2

--- Active Records in Database ---
Slot [0]: ID=101  | Name=Alice           | Age=28

--- Database Menu ---
1. Add user record
2. Show all user records
3. Exit
Select option: 3

Unmapping and saving database to disk. Goodbye!
```
