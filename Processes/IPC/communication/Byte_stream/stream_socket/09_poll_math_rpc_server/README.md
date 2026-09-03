# Concurrent Math RPC Server (ADD, SUB, MUL) via poll()
A lightweight Remote Procedure Call (RPC) math calculation service serving multiple concurrent clients over TCP stream sockets (`AF_INET`, `SOCK_STREAM`) with event-driven `poll()` multiplexing.
## Description
This project implements a binary command-parsing arithmetic RPC microservice:
1. **Server (`server.c`)**:
   - Manages active client sockets concurrently via `poll()`.
   - Parses text commands formatted as `<OPCODE> <NUM1> <NUM2>`:
     - `ADD <n1> <n2>`: Computes \(n_1 + n_2\).
     - `SUB <n1> <n2>`: Computes \(n_1 - n_2\).
     - `MUL <n1> <n2>`: Computes \(n_1 \times n_2\).
   - Returns formatted response strings (`Result: <val>\n`) or error diagnostic strings.
   - Cleans up client state on disconnection without disrupting other clients.
2. **Client (`client.c`)**:
   - Connects to `127.0.0.1:8080`.
   - Provides an interactive REPL command prompt to send arithmetic requests and render RPC return values.
3. Implements strict error validation on all network calls.
## Project Structure
```text
09_poll_math_rpc_server/
├── client.c
├── Makefile
├── README.md
└── server.c
```
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS)
## Building
To compile both server and client binaries, run:
```bash
make
```
To clean up built binaries:
```bash
make clean
```
## Running
1. **Start the Math RPC server:**
   ```bash
   ./server
   ```
2. **In one or more terminals, connect clients:**
   ```bash
   ./client
   ```
## Usage Examples
**Server Console:**
```text
============================================
||       POLL MATH RPC SOCKET SERVER      ||
============================================

Math RPC Server listening on port 8080... (Commands: ADD, SUB, MUL)

[CONNECT] Client connected (FD: 4, IP: 127.0.0.1)
[RPC] -> Request from FD 4: "ADD 150 250"
[RPC] -> Request from FD 4: "MUL 12 12"
[RPC] -> Request from FD 4: "SUB 100 37"
```

**Client Console:**
```text
============================================
||       POLL MATH RPC SOCKET CLIENT      ||
============================================

Connecting to Math RPC Server at 127.0.0.1:8080...
[SUCCESS] Connected to Math RPC Server! Examples: 'ADD 10 20', 'SUB 50 15', 'MUL 6 7'

RPC Command (or 'exit'): ADD 150 250
Server -> Result: 400

RPC Command (or 'exit'): MUL 12 12
Server -> Result: 144

RPC Command (or 'exit'): SUB 100 37
Server -> Result: 63

RPC Command (or 'exit'): exit
Closing connection...
```
