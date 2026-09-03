# Dynamic String Builder with Realloc
A C program demonstrating dynamic buffer expansion at runtime using `realloc()` to build arbitrary-length sentences from user word inputs.
## Description
This program demonstrates dynamic memory management with `realloc()`:
1. Initializes a heap-allocated buffer with a small baseline capacity (10 bytes).
2. Interactively reads incoming words from standard input (`stdin`).
3. Terminates input accumulation when the user enters the `"STOP"` sentinel.
4. Calculates the required memory for each word addition (`strlen(sentence) + strlen(word) + 2`).
5. When the required size exceeds current buffer capacity, calls `realloc()` to expand the allocated heap buffer, preventing memory overflow.
6. Concatenates words into a formatted sentence and frees the final buffer.
## Features
- Dynamic buffer resizing using `realloc()`.
- Safe temporary pointer handling to prevent memory leaks on `realloc` failure.
- Bounded input reading with `%127s`.
- Sentinel-controlled loop termination (`STOP`).
- Standard C17 compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
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
./dynamic_string_builder
```
## Usage Examples
**Dynamic String Builder Output Example:**
```text


Dynamic String Builder with Realloc

Enter words to build a sentence. Enter 'STOP' to finish.

Enter word: The
Enter word: quick
  [Buffer expanded: new capacity = 22 bytes]
Enter word: brown
Enter word: fox
  [Buffer expanded: new capacity = 46 bytes]
Enter word: jumps
Enter word: STOP

[STOP word received. Exiting input mode.]

--- Assembled Sentence ---
"The quick brown fox jumps"
Total Length: 25 characters

Memory freed successfully.
```
