# Remote Socket Logging Daemon
A network client-server logging daemon where distributed client applications transmit log events over a TCP stream socket (`AF_INET`, `SOCK_STREAM`) and the server aggregates them into a persistent disk file (`server_logs.txt`).
## Description
This project implements a remote logging architecture:
1. **Server (`server.c`)**:
   - Listens on `PORT 8080` with `SO_REUSEADDR`.
   - Accepts client connections.
   - Appends incoming log payloads to `server_logs.txt` prefixed with `[LOG_RECEIVED]`.
   - Returns a confirmation acknowledgment (`~Saved~`) to the client.
2. **Client (`client.c`)**:
   - Connects to the logging server at `127.0.0.1:8080`.
   - Captures log messages and sends them across the network stream.
   - Waits for the server's save acknowledgment before closing.
3. Implements strict error validation on all network and file I/O operations.
## Project Structure
```text
02_socket_remote_logger/
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
To clean up built binaries and generated log files:
```bash
make clean
```
## Running
1. **Start the server daemon in one terminal:**
   ```bash
   ./server
   ```
2. **In a second terminal, send a log entry via the client:**
   ```bash
   ./client
   ```
3. **Inspect the aggregated server log file:**
   ```bash
   cat server_logs.txt
   ```
## Usage Examples
**Server Console:**
```text
============================================
||      REMOTE LOGGER SOCKET SERVER       ||
============================================

Logger daemon listening on port 8080... Waiting for incoming logs...

[SUCCESS] Client connected! (IP: 127.0.0.1, Port: 44192)
[SERVER] -> Log entry received from client: "Application boot sequence initialized successfully"
[SERVER] -> Appended to 'server_logs.txt'.
[SERVER] -> Connection handled and closed cleanly.
```

**Client Console:**
```text
============================================
||      REMOTE LOGGER SOCKET CLIENT       ||
============================================

Connecting to logger server at 127.0.0.1:8080...
[SUCCESS] Connected to Remote Logger Server!

Enter log message to transmit: Application boot sequence initialized successfully

Server Response: 
~Saved~
```
