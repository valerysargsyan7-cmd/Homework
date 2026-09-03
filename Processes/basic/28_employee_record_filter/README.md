# Binary Employee Record Serialization & Filtering
A C program demonstrating binary record persistence of `struct Employee` datasets, automated record counting via `ftell()`, and conditional filtering in a child process.
## Description
This program demonstrates binary database simulation across processes:
1. The user inputs records for `struct Employee` (`id`, `name`, `salary`).
2. The parent writes the raw struct binary memory blocks to `employees.bin` via `fwrite()`.
3. A child process is spawned, opens the binary file, calculates total worker records using `ftell(fp) / sizeof(struct Employee)`, and dynamically allocates memory with `calloc()`.
4. The child loads all employee records with `fread()` and filters for records with salaries strictly greater than \$100,000.
5. The parent reaps the child and cleans up heap memory.
## Features
- Dynamic memory allocation for struct arrays.
- High-efficiency binary serialization with `fwrite()` and `fread()`.
- Record count calculation from file size (`ftell()`).
- In-memory conditional filtering.
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
To clean up built binaries and generated binary data files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./employee_record_filter
```
## Usage Examples
**Employee Record Filter Output Example:**
```text


Binary Employee Record Serialization & Filtering

Enter data for 3 employees:

Enter Employee 1 ID: 101
Enter Employee 1 Name: Alice
Enter Employee 1 Salary: 125000

Enter Employee 2 ID: 102
Enter Employee 2 Name: Bob
Enter Employee 2 Salary: 85000

Enter Employee 3 ID: 103
Enter Employee 3 Name: Charlie
Enter Employee 3 Salary: 140000

[PARENT] -> Saved 3 employee records to 'employees.bin'.

[CHILD] -> Read 3 employee records. Filtering (Salary > $100,000):
------------------------------------------------------------
ID: 101  | Name: Alice           | Salary: $125000.00
ID: 103  | Name: Charlie         | Salary: $140000.00
------------------------------------------------------------
[PARENT] -> Child filtering complete.
```
