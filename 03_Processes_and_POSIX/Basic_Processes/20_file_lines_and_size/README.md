# File Lines Reader & Size Calculation
A C program demonstrating multi-line text file writing, formatted line-by-line reading with `fgets()`, and file size calculation using `fseek()` and `ftell()`.
## Description
This program demonstrates basic text file inspection:
1. **Creation**: Writes 3 sample strings into `Reading_file.txt` using the low-level POSIX `write()` system call.
2. **Line Enumeration**: `read_lines()` opens the stream using `fopen()` and iterates over the file with `fgets()`, outputting each line prefixed by its line number (`1: ...`, `2: ...`).
3. **Size Calculation**: `get_size()` seeks to the end of the stream using `fseek(SEEK_END)` and retrieves the total file size in bytes using `ftell()`.
## Features
- Low-level POSIX file creation and writing.
- Safe buffer-bounded line reading with `fgets()`.
- Exact stream size measurement via `fseek()` and `ftell()`.
- Error handling on stream opening and seeking.
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
To clean up built binaries and created test files:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./file_lines_and_size
```
## Usage Examples
**File Lines Reader Output Example:**
```text


File Lines Reader & Size Calculation

--- Reading Line by Line ---
1: Hello my name is John Smith
2: Hello my name is Rick Sanchez
3: Hello my name is Morty Smith 

--- File Size Calculation ---

[The total size of 'Reading_file.txt' is: 87 bytes]
```
