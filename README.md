# C & POSIX Learning Workspace

A structured collection of C programming exercises, POSIX systems-programming examples, and recovered course materials. The repository is organized so learners can move from core language concepts to memory management, processes, inter-process communication, signals, and file handling.

## What is included

- **C fundamentals** — arithmetic, arrays, bitwise operations, conditional logic, enumerations, loops, strings, and structures.
- **Memory management** — examples covering dynamic allocation with `malloc()` and `calloc()`.
- **Processes and POSIX** — process creation, file I/O, standard-stream redirection, pipes, memory mapping, and signals.
- **Source archive** — the original Git metadata and compressed objects preserved for traceability and potential future recovery.
- **Applications** — local installation-related material kept outside the source-code topics.

## Repository layout

```text
.
├── 00_Source_Archive/              # Original Git objects and metadata
├── 01_C_Fundamentals/              # Language-level C exercises
├── 02_Memory_Management/           # Dynamic memory examples
├── 03_Processes_and_POSIX/         # Processes, IPC, signals, and file operations
├── 04_Applications/                # Local application-related files
└── homework18.c                    # Original Homework repository source file
```

Each topic directory contains its own `README.md` describing the material available there. Some recovered exercise directories contain a full source file, while others contain only a `Makefile` or an exercise README; this reflects the source material that was available during recovery.

## Requirements

- A C17-compatible compiler such as `gcc` or `clang`
- `make` for exercises that include a `Makefile`
- A POSIX-compatible operating system (Linux or macOS) for process, pipe, signal, and memory-mapping examples

## Build and run an exercise

Enter a directory that contains a complete exercise and run:

```bash
make
./<program-name>
```

Use the target name defined in that exercise's `Makefile`. To remove the compiled binary:

```bash
make clean
```

## Notes

- The original source hierarchy under `Fundamentals/`, `Memory/`, and `Processes/` is retained for the complete course collection; the numbered English directories provide a curated, documented organization of recovered materials.
- `04_Applications/ChatGPT/chatgpt_amd64.deb` is intentionally ignored by Git because its size exceeds GitHub's normal 100 MB file limit.
- Network and GIS exercises are not part of the recovered subset in the numbered directories. The original course tree may include additional networking material.

## License

No license information was provided with the source material. Treat the code as course material unless the repository owner specifies otherwise.
