# Personal Info
A C program demonstrating union-based storage, enum-tagged variant records, struct composition, and input validation with retry-on-invalid-choice.
## Description
This program prompts the user to enter a name, an ID type (ID number or passport number), and the corresponding identifier for 3 people, storing each as a `struct Person` record in an array (`persona[3]`). The identifier itself is stored in a `union Identifier`, interpreted as either an integer ID or a passport string depending on the `enum IdType` tag. Invalid type choices are rejected and re-prompted for the same person slot without consuming it. After all records are entered, the program prints each person's name and their corresponding identifier.
## Features
- Union-based storage (`union Identifier`) for either an integer ID or a passport string.
- Enum-tagged variant (`enum IdType`: ID_NUM, PASSPORT) selecting which union member is valid.
- Struct-based storage (`struct Person`) combining name, type, and identifier.
- Interactive per-field console input prompts and validation.
- Retry-on-invalid-type logic that re-prompts without skipping a person slot.
- Bounded name and passport input (`%19s`) to prevent buffer overflow.
- Error handling for invalid name, type, ID, or passport inputs.
- Standard C17 compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
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
./personal_info
```
## Usage Examples
**Personal Info Example:**
```text


Personal info

Enter your name: Alice
Enter your type ID_NUM - 0, PASSPORT - 1: 0
Enter your ID: 12345
Enter your name: Bob
Enter your type ID_NUM - 0, PASSPORT - 1: 9
[ERROR] Invalid ID type. Please enter 0 or 1.
Enter your name: Bob
Enter your type ID_NUM - 0, PASSPORT - 1: 1
Enter your passport number: AB1234567
Enter your name: Carl
Enter your type ID_NUM - 0, PASSPORT - 1: 0
Enter your ID: 999

People information:

Name: Alice
ID: 12345

Name: Bob
Passport: AB1234567

Name: Carl
ID: 999
```
**Invalid ID Error Example:**
```text


Personal info

Enter your name: Dan
Enter your type ID_NUM - 0, PASSPORT - 1: 0
Enter your ID: x
[ERROR] Invalid ID input.
```