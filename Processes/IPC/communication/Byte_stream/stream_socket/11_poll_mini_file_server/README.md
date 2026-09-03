# Concurrent File Server Daemon via poll()
A non-blocking TCP file server daemon serving local file queries to multiple concurrent clients simultaneously over stream sockets (`AF_INET`, `SOCK_STREAM`) with `poll()` multiplexing.
## Description
This project demonstrates a single-threaded concurrent file server:
1. **Server (`server.c`)**:
   - Creates sample files (`sample_doc.txt`, `empty_doc.txt`) upon startup for self-contained testing.
   - Listens on `PORT 8080` with `SO_REUSEADDR` and `poll()` event multiplexing.
   - Parses client file path requests and responds appropriately:
     - File exists and has content $\to$ loads and transmits file content.
     - File does not exist $\to$ responds `FILE NOT FOUND!\n`.
     - File is 0 bytes $\to$ responds `FILE EMPTY!\n`.
   - Cleans up and removes disconnected clients from the polling array without server stalls.
2. **Client (`client.c`)**:
   - Connects to `127.0.0.1:8080`.
   - Queries filenames and displays returned file content.
3. Implements exhaustive error validation on all network and file I/O operations.
## Project Structure
```text
11_poll_mini_file_server/
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
To clean up built binaries and sample files:
```bash
make clean
```
## Running
1. **Start the file server daemon:**
   ```bash
   ./server
   ```
2. **In one or more terminals, run client file fetchers:**
   ```bash
   ./client
   ```
## Usage Examples
**Server Console:**
```text
============================================
||      POLL MINI FILE SERVER DAEMON      ||
============================================

File Server listening on port 8080... Ready to serve files via poll().

[CONNECT] File client connected (FD: 4)
[FILE REQUEST] FD 4 requested file: "sample_doc.txt"
[FILE REQUEST] FD 4 requested file: "non_existent.txt"
```

**Client Console:**
```text
============================================
||      POLL MINI FILE SOCKET CLIENT      ||
============================================

Connecting to File Server at 127.0.0.1:8080...
[SUCCESS] Connected to File Server! (Try: 'sample_doc.txt', 'empty_doc.txt', 'unknown.txt')

Enter file name to fetch (or 'exit'): sample_doc.txt

====[ FILE RESPONSE ]====
This is sample_doc.txt retrieved from the Mini File Server!
=========================

Enter file name to fetch (or 'exit'): non_existent.txt

====[ FILE RESPONSE ]====
FILE NOT FOUND!
=========================
```
