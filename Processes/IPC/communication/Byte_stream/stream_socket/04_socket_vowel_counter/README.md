# Multi-Byte Text Stream Vowel Frequency Analyzer
A TCP client-server application implementing text parsing and character classification over network stream sockets (`AF_INET`, `SOCK_STREAM`).
## Description
This project demonstrates text payload transmission and linguistic metric calculation over network sockets:
1. **Server (`server.c`)**:
   - Listens on `PORT 8080`.
   - Accepts client connections and ingests multi-byte text passages.
   - Iterates through the character stream, calculating the total occurrence of vowels (`a, e, i, o, u`, case-insensitively).
   - Formats the response (`Vowels Count: <count>`) and returns it across the network socket.
2. **Client (`client.c`)**:
   - Connects to `127.0.0.1:8080`.
   - Transmits a sample text document for analysis and displays the server's computed vowel count.
3. Implements comprehensive error checking on all network socket operations.
## Project Structure
```text
04_socket_vowel_counter/
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
1. **Start the server in one terminal:**
   ```bash
   ./server
   ```
2. **In a second terminal, trigger the client analyzer:**
   ```bash
   ./client
   ```
## Usage Examples
**Server Console:**
```text
============================================
||      VOWEL COUNTER SOCKET SERVER       ||
============================================

Vowel Counter Server listening on port 8080... Waiting for client...

[SUCCESS] Client connected! (IP: 127.0.0.1, Port: 48112)
[SERVER] -> Received text passage (146 bytes).
[SERVER] -> Total vowels counted: 44
[SERVER] -> Response dispatched and connection closed.
```

**Client Console:**
```text
============================================
||      VOWEL COUNTER SOCKET CLIENT       ||
============================================

Connecting to Vowel Counter Server at 127.0.0.1:8080...
[SUCCESS] Connected to Vowel Counter Server!

[CLIENT] -> Transmitting text passage for analysis:
"Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the standard dummy text ever since the 1500s."

[ANALYSIS RESULT FROM SERVER] -> Vowels Count: 35
```
