# State-Machine Socket Number Guessing Game Protocol
An interactive client-server game application implementing a state-machine query-response protocol over TCP stream sockets (`AF_INET`, `SOCK_STREAM`).
## Description
This project implements an interactive multi-turn protocol:
1. **Server (`server.c`)**:
   - Manages a secret target integer (`42`).
   - Receives consecutive guesses from connected player clients.
   - Evaluates the guess:
     - `guess < secret`: Responds `"Higher"`.
     - `guess > secret`: Responds `"Lower"`.
     - `guess == secret`: Responds `"Correct"` and concludes the session.
2. **Client (`client.c`)**:
   - Connects to `127.0.0.1:8080`.
   - Interactively queries the user for numerical guesses and transmits them over the socket.
   - Parses feedback until receiving `"Correct"`.
3. Implements comprehensive error checking on all network calls.
## Project Structure
```text
05_socket_number_guessing_game/
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
1. **Start the game server in one terminal:**
   ```bash
   ./server
   ```
2. **In a second terminal, start the game client:**
   ```bash
   ./client
   ```
## Usage Examples
**Server Console:**
```text
============================================
||     NUMBER GUESSING SOCKET SERVER      ||
============================================

Game server online (Secret number: 42).
Listening on port 8080...

[SUCCESS] Player connected! (IP: 127.0.0.1, Port: 50124)
[GAME] -> Attempt 1: Player guessed 20
[GAME] -> Attempt 2: Player guessed 50
[GAME] -> Attempt 3: Player guessed 42
[GAME] -> Player guessed correctly in 3 attempts! Game over.
```

**Client Console:**
```text
============================================
||     NUMBER GUESSING SOCKET CLIENT      ||
============================================

Connecting to Game Server at 127.0.0.1:8080...
[SUCCESS] Connected to Game Server! Guess the secret number (1..100):

Enter your guess: 20
Server Feedback -> [Higher]

Enter your guess: 50
Server Feedback -> [Lower]

Enter your guess: 42
Server Feedback -> [Correct]

CONGRATULATIONS! You guessed the secret number in 3 attempts!
```
