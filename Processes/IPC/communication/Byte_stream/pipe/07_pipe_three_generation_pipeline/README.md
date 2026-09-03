# Three-Generation Pipe Pipeline: Parent -> Child -> Grandchild
A C program demonstrating a linear multi-generation processing pipeline connecting three process generations (Parent $\to$ Child $\to$ Grandchild) via chained POSIX pipes.
## Description
This program models multi-stage stream processing across a process lineage:
1. Two pipes are allocated:
   - `fds_1`: Channeled from Parent to Child.
   - `fds_2`: Channeled from Child to Grandchild.
2. **Generation 1 (Parent)**: Transmits initial integer `5` over `fds_1` to the Child.
3. **Generation 2 (Child)**: Reads `5` from `fds_1`, transforms the payload by doubling it ($5 \times 2 = 10$), forks Generation 3 (Grandchild), and writes `10` over `fds_2`.
4. **Generation 3 (Grandchild)**: Reads the final transformed value from `fds_2` and displays it.
5. All intermediate descriptors are closed to ensure EOF detection and prevent pipe deadlocks, with cascade process reaping.
## Features
- Multi-generation process topology (3-tier pipeline).
- Chained stream processing.
- Clean hierarchical descriptor closure and wait reaping.
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
./pipe_three_generation_pipeline
```
## Usage Examples
**Three Generation Pipeline Output Example:**
```text


Three-Generation Pipe Pipeline: Parent -> Child -> Grandchild

[PARENT (Gen 1)]     -> Sending initial seed value: 5 to Child via Pipe 1...
[CHILD (Gen 2)]      -> Received value: 5 from Parent.
[CHILD (Gen 2)]      -> Doubled value: 10 (* 2). Spawning Grandchild...
[GRANDCHILD (Gen 3)] -> Received final pipeline payload: 10
[PARENT (Gen 1)]     -> Entire multi-generation pipeline completed.
```
