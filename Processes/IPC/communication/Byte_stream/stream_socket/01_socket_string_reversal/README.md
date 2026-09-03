# Stream Socket String Reversal Service
A TCP client-server application implementing a remote string reversal service over IPv4 stream sockets (`AF_INET`, `SOCK_STREAM`).
## Description
This project demonstrates stream socket client-server communication using POSIX network APIs:
1. **Server (`server.c`)**:
   - Creates a stream socket, sets `SO_REUSEADDR`, and binds to `0.0.0.0:8080`.
   - Listens with a backlog of 5 connections and accepts incoming clients.
   - Receives text payloads via `recv()`, applies an in-place two-pointer reversal algorithm on the character buffer, and sends the reversed string back via `send()`.
2. **Client (`client.c`)**:
   - Connects to `127.0.0.1:8080`.
   - Captures user input, transmits it to the server, and prints the reversed string response.
3. Enforces thorough error checking across all socket and I/O system calls.
## Project Structure
```text
01_socket_string_reversal/
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
To compile both the server and client binaries, run:
```bash
make
```
To clean up built binaries:
```bash
make clean
```
## Running
1. **Start the server in one terminal:**
   ```bash
   ./server
   ```
2. **In a second terminal, start the client:**
   ```bash
   ./client
   ```
## Usage Examples
**Server Output:**
```text
============================================
||     STRING REVERSAL SOCKET SERVER      ||
============================================

Server listening on port 8080... Waiting for client connection...

[SUCCESS] Client connected! (IP: 127.0.0.1, Port: 42104)

[SERVER] -> Received text from client:
  "Hello Network Sockets!"

[SERVER] -> Reversed string:
  "!stekcoS krowteN olleH"

[SERVER] -> Reversed result dispatched to client successfully.
```

**Client Output:**
```text
============================================
||     STRING REVERSAL SOCKET CLIENT      ||
============================================

Connecting to server at 127.0.0.1:8080...
[SUCCESS] Connected to String Reversal Server!

Enter text to reverse: Hello Network Sockets!

[RESULT] Server returned reversed text:
  "!stekcoS krowteN olleH"
```
