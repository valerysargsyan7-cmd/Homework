# Unnamed Pipe IPC: Process Password Validator
A C program demonstrating privilege/verification separation between processes where credential inputs collected by a parent process are passed through an unnamed pipe to an isolated child validator process.
## Description
This program models credential validation across process boundaries:
1. `pipe()` creates the IPC communication channel.
2. The parent process captures a password string from user input.
3. The parent writes the credential string into the pipe and closes its write descriptor.
4. The isolated child process reads the password stream, performs a string comparison (`strcmp`) against the target secret (`"abdulhamid"`), and determines authorization status (`ACCESS GRANTED` vs `ACCESS DENIED`).
5. The parent awaits validation completion via `wait()`.
## Features
- Isolation of authentication verification logic.
- Secure inter-process string transmission.
- Input validation and buffer protection.
- Standard C17 and POSIX compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
- A POSIX-compliant system (e.g. Linux or macOS)
## Building
To compile the project, run:
```bash
make
```
To clean up built binaries:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./pipe_password_validator
```
## Usage Examples
**Pipe Password Validator Output Example:**
```text


Unnamed Pipe IPC: Process Password Validator

Enter password to authenticate: password123
[PARENT] -> Sending password to Authenticator child process via pipe...
[AUTHENTICATOR CHILD] -> Password match! Status: [ACCESS GRANTED]
[PARENT] -> Authentication verification concluded.
```
