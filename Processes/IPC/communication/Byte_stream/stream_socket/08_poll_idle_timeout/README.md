# Server Idle Timeout Handling & Dynamic Client Eviction via poll()
A TCP server implementing periodic event timeout handling and dynamic client disconnection management using the POSIX `poll()` system call.
## Description
This project demonstrates robust timeout and client eviction handling in an event loop:
1. **Server (`server.c`)**:
   - Executes `poll(fds, nfds, TIMEOUT_MS)` with a 5000ms (5 seconds) timeout threshold.
   - When no network activity occurs within the timeout interval (`poll()` returns `0`), the server logs an idle heartbeat and continues listening without blocking indefinitely.
   - When a client transmits data, it processes the request and responds.
   - When a client closes the socket or terminates unexpectedly (`recv() <= 0`), the server detects the disconnection, closes the descriptor, and compacts the `fds` array (`fds[i] = fds[nfds - 1]; nfds--; i--;`).
2. **Client (`client.c`)**:
   - Connects to `127.0.0.1:8080`, sends test payloads, and prints the server's response.
3. Implements comprehensive error checking on all network calls.
## Project Structure
```text
08_poll_idle_timeout/
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
1. **Start the timeout server:**
   ```bash
   ./server
   ```
2. **In a second terminal, execute the client:**
   ```bash
   ./client
   ```
## Usage Examples
**Server Console:**
```text
============================================
||     POLL IDLE TIMEOUT SOCKET SERVER    ||
============================================

Server listening on port 8080 (Poll timeout: 5000 ms)...

[HEARTBEAT #1] Server is idle (No activity across 1 descriptors for 5000 ms)...
[HEARTBEAT #2] Server is idle (No activity across 1 descriptors for 5000 ms)...

[CONNECT] New client attached (FD: 4, IP: 127.0.0.1)
[SERVER] -> Received data from FD 4: "Network socket timeout testing message payload."
[DISCONNECT] Client on FD 4 closed connection.

[HEARTBEAT #3] Server is idle (No activity across 1 descriptors for 5000 ms)...
```
