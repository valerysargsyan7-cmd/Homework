# File Append Logger
A C program demonstrating file append operations using standard C stream I/O (`fopen()`, `fprintf()`, `fflush()`, `fclose()`).
## Description
This program demonstrates standard I/O append logging:
1. `append_log()` opens `File.log` in append mode (`"a"`), ensuring that existing content is preserved.
2. Writes a formatted log timestamp/entry (`"[LOG]: User entered\n"`) using `fprintf()`.
3. Flushes and closes the stream cleanly.
4. Reads and displays the updated log file.
## Features
- Standard stream appending via `fopen` with mode `"a"`.
- Explicit stream buffer flushing with `fflush()`.
- Clean error handling on stream initialization.
- Standard C17 compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
## Building
To compile the project, run:
```bash
make
```
To clean up built binaries and created log files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./file_append_logger
```
## Usage Examples
**File Append Logger Output Example:**
```text


File Append Logger

Log entry recorded successfully in File.log.

--- File Content (File.log) ---
[LOG]: User entered
```
