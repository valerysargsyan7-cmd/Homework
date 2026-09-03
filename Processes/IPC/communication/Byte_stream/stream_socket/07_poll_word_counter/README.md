# Concurrent Multi-Client Word Counter Server with poll()
A scalable TCP server application utilizing POSIX I/O multiplexing (`poll()`) to service multiple concurrent client word-count requests simultaneously within a single event-driven execution thread.
## Description
This project demonstrates non-blocking I/O event multiplexing over stream sockets:
1. **Server (`server.c`)**:
   - Manages a dynamic `struct pollfd` array monitoring both the listening socket and all active client connections.
   - When connection activity is detected on `fds[0]`, `accept()` registers new clients into the polling array without blocking.
   - When text data arrives from any connected client, the server isolates words across whitespace delimiters and returns the exact word count (`Words Count: <N>`).
   - When a client disconnects (`recv() <= 0`), the server closes the file descriptor and compacts the polling array.
2. **Client (`client.c`)**:
   - Connects to `127.0.0.1:8080`, transmits a text payload, and displays the server's analysis result.
3. Implements strict error validation on all network operations.
## Project Structure
```text
07_poll_word_counter/
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
1. **Start the poll server:**
   ```bash
   ./server
   ```
2. **Run one or more clients concurrently:**
   ```bash
   ./client
   ```
## Usage Examples
**Server Console:**
```text
============================================
||     POLL MULTI-CLIENT WORD COUNTER     ||
============================================

Word Counter Server active on port 8080 with poll() multiplexing.
Waiting for connections...

[CONNECT] New client attached (FD: 4, IP: 127.0.0.1, Port: 53100)
[SERVER] -> Received text from FD 4 (134 bytes).
[SERVER] -> Counted 16 words for client on FD 4.
[DISCONNECT] Client on FD 4 disconnected.
```

**Client Console:**
```text
============================================
||     WORD COUNTER SOCKET CLIENT         ||
============================================

Connecting to Word Counter Server at 127.0.0.1:8080...
[SUCCESS] Connected to Word Counter Server!

[CLIENT] -> Transmitting text string for word analysis:
  "Operating system multiplexing with poll enables high performance concurrent network servers without spawning threads or processes."

[ANALYSIS RESULT] -> Words Count: 16
```
