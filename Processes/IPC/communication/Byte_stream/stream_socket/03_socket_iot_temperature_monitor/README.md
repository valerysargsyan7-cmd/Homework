# IoT Sensor Stream Telemetry & Threshold Monitor
A client-server IoT telemetry monitoring system where simulated hardware sensor clients stream temperature readings over a TCP stream socket (`AF_INET`, `SOCK_STREAM`), and the server parses the metric and generates safety alerts when thresholds are exceeded.
## Description
This project simulates real-time IoT monitoring over network sockets:
1. **Server (`server.c`)**:
   - Listens on `PORT 8080`.
   - Receives telemetry messages formatted as `TEMP : <value>`.
   - Dynamically parses the numeric reading using character classification.
   - Evaluates whether the reading exceeds the safety threshold (\(> 50^\circ\text{C}\)).
   - Dispatches `[ALERT] Dangerously high temperature detected!` for high temperatures, or `[OK] Temperature within normal operational limits.` for normal readings.
2. **Client (`client.c`)**:
   - Generates sensor readings and connects to the monitoring server at `127.0.0.1:8080`.
   - Transmits telemetry and outputs the server's evaluation.
3. Implements comprehensive error checking on all network calls.
## Project Structure
```text
03_socket_iot_temperature_monitor/
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
1. **Start the IoT server monitor:**
   ```bash
   ./server
   ```
2. **In a second terminal, trigger the sensor client:**
   ```bash
   ./client
   ```
## Usage Examples
**Server Console:**
```text
============================================
||     IoT MONITORING SOCKET SERVER       ||
============================================

IoT Monitor listening on port 8080... Waiting for sensor telemetry...

[SUCCESS] Sensor connected! (IP: 127.0.0.1, Port: 46210)
[SERVER] -> Telemetry payload received: "TEMP : 74"
[SERVER] -> Parsed Temperature: 74 C -> THRESHOLD EXCEEDED (> 50 C)!
```

**Client Console:**
```text
============================================
||     IoT SENSOR TELEMETRY CLIENT        ||
============================================

Connecting to IoT Monitor at 127.0.0.1:8080...
[SUCCESS] Connected to IoT Monitor!

[SENSOR] -> Reading current hardware sensor: 74 C
[SENSOR] -> Transmitting telemetry: "TEMP : 74"

Server Monitor Response:
[ALERT] Dangerously high temperature detected!
```
