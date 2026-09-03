# Full-Duplex Interactive Terminal Chat Session
A full-duplex interactive terminal chat application implementing turn-taking conversational dialogue and graceful session termination over TCP stream sockets (`AF_INET`, `SOCK_STREAM`).
## Description
This project implements a terminal-based peer-to-peer style interactive chat protocol between two endpoints:
1. **Server (`server.c`)**:
   - Creates a listening socket on `PORT 8080` with `SO_REUSEADDR`.
   - Accepts a client connection and enters a synchronized turn-taking dialogue loop.
   - Prints messages received from the client and prompts the server operator (`:> `) for an immediate response.
   - Detects the command `"exit"` from either party to conclude and close the connection gracefully.
2. **Client (`client.c`)**:
   - Connects to the chat server at `127.0.0.1:8080`.
   - Prompts the client operator (`:> `) to initiate conversation rounds.
   - Receives and renders server responses.
3. Implements comprehensive error checking on all socket and input operations.
## Project Structure
```text
06_socket_two_way_chat/
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
1. **Start the chat server in one terminal:**
   ```bash
   ./server
   ```
2. **In a second terminal, start the chat client:**
   ```bash
   ./client
   ```
## Usage Examples
**Server Console:**
```text
============================================
||       TWO-WAY CHAT SOCKET SERVER       ||
============================================

Chat server online. Listening on port 8080... Waiting for peer...

[SUCCESS] Peer connected! (IP: 127.0.0.1, Port: 52140)
Type 'exit' to conclude the chat session.


[CLIENT] :> Hello server!
[SERVER] :> Hello client, how are you?

[CLIENT] :> Everything is working perfectly over sockets!
[SERVER] :> exit

Closing chat session...
```

**Client Console:**
```text
============================================
||       TWO-WAY CHAT SOCKET CLIENT       ||
============================================

Connecting to Chat Server at 127.0.0.1:8080...
[SUCCESS] Connected to Chat Server! Type 'exit' to quit.

[CLIENT] :> Hello server!

[SERVER] :> Hello client, how are you?
[CLIENT] :> Everything is working perfectly over sockets!

[SERVER] :> exit

Server initiated session close. Exiting chat...
```
