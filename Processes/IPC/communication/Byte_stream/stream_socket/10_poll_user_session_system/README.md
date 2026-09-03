# Stateful User Session Registration & Message Routing Server via poll()
A multi-client user registration and message routing service maintaining in-memory client session metadata (`struct ClientInfo`) across non-blocking socket connections with `poll()`.
## Description
This project demonstrates stateful connection tracking across multiplexed clients:
1. **Server (`server.c`)**:
   - Maintains a `struct ClientInfo clients[]` table associated 1-to-1 with the `struct pollfd fds[]` array.
   - Initial message received from any newly connected client is treated as an authentication/registration handshake, binding their username to their socket descriptor.
   - Subsequent messages received on that descriptor are tagged with the user's registered name (`[CHAT] '<name>' (FD <fd>) says: ...`).
   - On client disconnection, the server unregisters the user and removes the descriptor without disturbing other active sessions.
2. **Client (`client.c`)**:
   - Connects to `127.0.0.1:8080`.
   - Prompts for username registration followed by an interactive multi-message session.
3. Implements robust error handling on all system and network calls.
## Project Structure
```text
10_poll_user_session_system/
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
1. **Start the user session server:**
   ```bash
   ./server
   ```
2. **In one or more terminals, connect client users:**
   ```bash
   ./client
   ```
## Usage Examples
**Server Console:**
```text
============================================
||     POLL USER SESSION SYSTEM SERVER    ||
============================================

User Session Server listening on port 8080... Waiting for clients...

[CONNECT] New client socket attached (FD: 4)
[REGISTER] FD 4 registered as username: 'Alice'
[CONNECT] New client socket attached (FD: 5)
[REGISTER] FD 5 registered as username: 'Bob'

[CHAT] 'Alice' (FD 4) says: "Hello Bob!"
[CHAT] 'Bob' (FD 5) says: "Hey Alice, nice to meet you!"
[DISCONNECT] User 'Alice' (FD 4) disconnected.
```

**Client Console (Alice):**
```text
============================================
||     POLL USER SESSION SOCKET CLIENT    ||
============================================

Connecting to User Session Server at 127.0.0.1:8080...
[SUCCESS] Connected to Server!

Enter your username to register: Alice
Server: Welcome Alice! You are registered. You can now send messages.

Message (or 'exit'): Hello Bob!
Server: Message received!

Message (or 'exit'): exit
Closing session...
```
