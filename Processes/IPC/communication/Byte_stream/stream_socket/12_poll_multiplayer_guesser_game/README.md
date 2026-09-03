# Multiplayer Broadcast Number Guessing Game Server via poll()
A real-time multiplayer network game server implementing multi-client state tracking and broadcast victory/game-over notifications over TCP stream sockets (`AF_INET`, `SOCK_STREAM`) with `poll()` event multiplexing.
## Description
This project implements a concurrent multiplayer gaming arena:
1. **Server (`server.c`)**:
   - Generates a secret target number between 1 and 100.
   - Accepts multiple player connections simultaneously without threads using `poll()`.
   - Processes individual player guesses asynchronously:
     - Sends private `HIGHER!\n` or `LOWER!\n` hints to the guessing player.
     - When any player guesses the target number correctly:
       - Sends `*** YOU WON! CONGRATULATIONS! ***\n` to the winner.
       - Broadcasts `GAME OVER: Another player guessed the correct number first!\n` to all competing players in the room.
       - Closes client connections, generates a new secret number, and resets the lobby for subsequent rounds.
2. **Client (`client.c`)**:
   - Connects to `127.0.0.1:8080` and enters the live competitive guessing loop.
3. Implements comprehensive error checking across all system and socket operations.
## Project Structure
```text
12_poll_multiplayer_guesser_game/
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
1. **Start the multiplayer game server:**
   ```bash
   ./server
   ```
2. **In two or more terminals, connect competing players:**
   ```bash
   ./client
   ```
## Usage Examples
**Server Console:**
```text
============================================
||    POLL MULTIPLAYER GUESSER SERVER     ||
============================================

Multiplayer Game Server active on port 8080.
Secret target number generated: 65
Waiting for players...

[PLAYER JOINED] FD 4 entered the game room (IP: 127.0.0.1)
[PLAYER JOINED] FD 5 entered the game room (IP: 127.0.0.1)

[GAME ACTION] -> FD 4 guessed: 50 (Secret: 65)
[GAME ACTION] -> FD 5 guessed: 70 (Secret: 65)
[GAME ACTION] -> FD 4 guessed: 65 (Secret: 65)

[GAME WINNER] -> FD 4 guessed correctly (65)! Broadcasting game over...

--- Round Reset --- New secret generated (82). Waiting for players...
```

**Client 1 (Winner):**
```text
Your guess: 50
Server Feedback -> HIGHER!

Your guess: 65
Server Feedback -> *** YOU WON! CONGRATULATIONS! ***
```

**Client 2 (Competing Player):**
```text
Your guess: 70
Server Feedback -> LOWER!

Server Feedback -> GAME OVER: Another player guessed the correct number first!
```
